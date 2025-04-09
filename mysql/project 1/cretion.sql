CREATE DATABASE IF NOT EXISTS RetailEcosystem;

USE RetailEcosystem;

-- Main Table to Track Product Flow from GlobalStore to End User
-- Already defined relevant tables, this acts as an anchor or reference entity if needed
-- No separate 'Main' table needed, the architecture is modular.
-- All key flows are traceable via joins across the following:
-- GlobalStore → RetailerGlobal → Retailer → Store → StoreInventory → UserOrder → OrderDescription → User

-- Category Table
CREATE TABLE Category (
    category_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL UNIQUE,
    description TEXT,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Brand Table
CREATE TABLE Brand (
    brand_id INT PRIMARY KEY AUTO_INCREMENT,
    category_id INT NOT NULL,
    name VARCHAR(100) NOT NULL,
    origin_country VARCHAR(100),
    logo_url TEXT,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (category_id) REFERENCES Category(category_id)
);

-- Global Store Table (Product Types)
CREATE TABLE GlobalStore (
    product_id INT PRIMARY KEY AUTO_INCREMENT,
    brand_id INT NOT NULL,
    name VARCHAR(100) NOT NULL,
    size VARCHAR(50),
    unit ENUM('ml', 'g', 'kg', 'L', 'pcs') DEFAULT 'pcs',
    stock_quantity INT DEFAULT 0,
    price DECIMAL(10,2),
    manufacture_date DATE,
    expiry_date DATE,
    sku_code VARCHAR(100) UNIQUE,
    barcode VARCHAR(100) UNIQUE,
    description TEXT,
    image_url TEXT,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (brand_id) REFERENCES Brand(brand_id)
);

-- Retailer Table
CREATE TABLE Retailer (
    retailer_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    email VARCHAR(100) UNIQUE,
    phone VARCHAR(20),
    address TEXT,
    gst_number VARCHAR(50),
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Store Table (Local Stores)
CREATE TABLE Store (
    store_id INT PRIMARY KEY AUTO_INCREMENT,
    retailer_id INT NOT NULL,
    name VARCHAR(100),
    email VARCHAR(100),
    phone VARCHAR(20),
    location TEXT,
    contact_info TEXT,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (retailer_id) REFERENCES Retailer(retailer_id)
);

-- Retailer-Store Supply Relationship
CREATE TABLE RetailerStore (
    retailer_id INT,
    store_id INT,
    supply_terms TEXT,
    PRIMARY KEY (retailer_id, store_id),
    FOREIGN KEY (retailer_id) REFERENCES Retailer(retailer_id),
    FOREIGN KEY (store_id) REFERENCES Store(store_id)
);

-- Retailer-GlobalStore Supply Relationship
CREATE TABLE RetailerGlobal (
    retailer_id INT,
    product_id INT,
    supply_price DECIMAL(10,2),
    PRIMARY KEY (retailer_id, product_id),
    FOREIGN KEY (retailer_id) REFERENCES Retailer(retailer_id),
    FOREIGN KEY (product_id) REFERENCES GlobalStore(product_id)
);

-- Store Inventory
CREATE TABLE StoreInventory (
    store_id INT,
    product_id INT,
    quantity INT DEFAULT 0,
    restock_level INT DEFAULT 10,
    last_updated DATETIME DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (store_id, product_id),
    FOREIGN KEY (store_id) REFERENCES Store(store_id),
    FOREIGN KEY (product_id) REFERENCES GlobalStore(product_id)
);

-- User Table
CREATE TABLE User (
    user_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    email VARCHAR(100) UNIQUE,
    phone VARCHAR(15),
    address TEXT,
    password_hash TEXT,
    registered_on DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Order Table
CREATE TABLE UserOrder (
    order_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT NOT NULL,
    store_id INT NOT NULL,
    order_date DATETIME DEFAULT CURRENT_TIMESTAMP,
    status ENUM('PENDING', 'PROCESSING', 'SHIPPED', 'COMPLETED', 'CANCELLED') DEFAULT 'PENDING',
    total_amount DECIMAL(10,2),
    delivery_address TEXT,
    payment_method ENUM('COD', 'ONLINE'),
    FOREIGN KEY (user_id) REFERENCES User(user_id),
    FOREIGN KEY (store_id) REFERENCES Store(store_id)
);

-- Order Description Table
CREATE TABLE OrderDescription (
    order_id INT,
    product_id INT,
    quantity INT,
    price DECIMAL(10,2),
    discount DECIMAL(10,2) DEFAULT 0.00,
    PRIMARY KEY (order_id, product_id),
    FOREIGN KEY (order_id) REFERENCES UserOrder(order_id),
    FOREIGN KEY (product_id) REFERENCES GlobalStore(product_id)
);

-- Order History Table
CREATE TABLE OrderHistory (
    history_id INT PRIMARY KEY AUTO_INCREMENT,
    order_id INT,
    user_id INT,
    store_id INT,
    order_date DATETIME,
    completed_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (order_id) REFERENCES UserOrder(order_id),
    FOREIGN KEY (user_id) REFERENCES User(user_id),
    FOREIGN KEY (store_id) REFERENCES Store(store_id)
);

-- Trigger to move completed orders to history
DELIMITER //
CREATE TRIGGER move_to_history AFTER UPDATE ON UserOrder
FOR EACH ROW
BEGIN
    IF NEW.status = 'COMPLETED' AND OLD.status != 'COMPLETED' THEN
        INSERT INTO OrderHistory (order_id, user_id, store_id, order_date)
        VALUES (NEW.order_id, NEW.user_id, NEW.store_id, NEW.order_date);
    END IF;
END;//
DELIMITER ;

-- User Payment
CREATE TABLE UserPayment (
    payment_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    store_id INT,
    order_id INT,
    amount DECIMAL(10,2),
    payment_mode ENUM('UPI', 'Card', 'NetBanking', 'Wallet'),
    payment_status ENUM('SUCCESS', 'PENDING', 'FAILED') DEFAULT 'SUCCESS',
    transaction_id VARCHAR(100),
    payment_date DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES User(user_id),
    FOREIGN KEY (store_id) REFERENCES Store(store_id),
    FOREIGN KEY (order_id) REFERENCES UserOrder(order_id)
);

-- Store Payment to Retailer
CREATE TABLE StorePayment (
    payment_id INT PRIMARY KEY AUTO_INCREMENT,
    store_id INT,
    retailer_id INT,
    amount DECIMAL(10,2),
    mode ENUM('BANK_TRANSFER', 'CASH', 'CHEQUE'),
    transaction_id VARCHAR(100),
    payment_date DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (store_id) REFERENCES Store(store_id),
    FOREIGN KEY (retailer_id) REFERENCES Retailer(retailer_id)
);

-- Retailer Payment to Global Store (Manufacturer)
CREATE TABLE RetailerPayment (
    payment_id INT PRIMARY KEY AUTO_INCREMENT,
    retailer_id INT,
    product_id INT,
    amount DECIMAL(10,2),
    payment_method ENUM('BANK_TRANSFER', 'UPI', 'CARD'),
    transaction_id VARCHAR(100),
    payment_date DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (retailer_id) REFERENCES Retailer(retailer_id),
    FOREIGN KEY (product_id) REFERENCES GlobalStore(product_id)
);

-- Store Ratings by Users
CREATE TABLE StoreRating (
    rating_id INT PRIMARY KEY AUTO_INCREMENT,
    store_id INT,
    user_id INT,
    rating INT CHECK (rating BETWEEN 1 AND 5),
    review TEXT,
    rated_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (store_id) REFERENCES Store(store_id),
    FOREIGN KEY (user_id) REFERENCES User(user_id)
);

-- User Wishlist
CREATE TABLE UserWishlist (
    user_id INT,
    product_id INT,
    added_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (user_id, product_id),
    FOREIGN KEY (user_id) REFERENCES User(user_id),
    FOREIGN KEY (product_id) REFERENCES GlobalStore(product_id)
);

-- User Cart
CREATE TABLE UserCart (
    user_id INT,
    product_id INT,
    quantity INT DEFAULT 1,
    added_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (user_id, product_id),
    FOREIGN KEY (user_id) REFERENCES User(user_id),
    FOREIGN KEY (product_id) REFERENCES GlobalStore(product_id)
);

-- Coupons Table
CREATE TABLE Coupon (
    coupon_id INT PRIMARY KEY AUTO_INCREMENT,
    code VARCHAR(50) UNIQUE NOT NULL,
    discount_percentage DECIMAL(5,2) CHECK (discount_percentage BETWEEN 0 AND 100),
    valid_from DATETIME,
    valid_till DATETIME,
    description TEXT,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Applied Coupons
CREATE TABLE AppliedCoupon (
    user_id INT,
    order_id INT,
    coupon_id INT,
    applied_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (user_id, order_id),
    FOREIGN KEY (user_id) REFERENCES User(user_id),
    FOREIGN KEY (order_id) REFERENCES UserOrder(order_id),
    FOREIGN KEY (coupon_id) REFERENCES Coupon(coupon_id)
);