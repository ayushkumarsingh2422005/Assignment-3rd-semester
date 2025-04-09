USE RetailEcosystem;

-- Category
INSERT INTO Category (name, description) VALUES
('Beverages', 'Drinks and refreshments'),
('Snacks', 'Packaged snacks and munchies');

-- Brand
INSERT INTO Brand (category_id, name, origin_country, logo_url) VALUES
(1, 'Coca-Cola', 'USA', 'https://example.com/coke-logo.png'),
(2, 'Lays', 'USA', 'https://example.com/lays-logo.png');

-- GlobalStore
INSERT INTO GlobalStore (brand_id, name, size, unit, stock_quantity, price, manufacture_date, expiry_date, sku_code, barcode, description, image_url) VALUES
(1, 'Coca-Cola Can', '330', 'ml', 1000, 35.00, '2024-03-01', '2025-03-01', 'COC330ML001', '1234567890123', 'Refreshing soft drink', 'https://example.com/coke330.png'),
(2, 'Lays Classic', '50', 'g', 800, 20.00, '2024-01-10', '2025-01-10', 'LAY50G001', '9876543210987', 'Classic salted potato chips', 'https://example.com/lays50g.png');

-- Retailer
INSERT INTO Retailer (name, email, phone, address, gst_number) VALUES
('RetailMart', 'contact@retailmart.com', '9876543210', '123 Main St, Cityville', 'GSTIN1234567890'),
('SuperSupply', 'info@supersupply.com', '9123456789', '456 Market St, Townburg', 'GSTIN0987654321');

-- Store
INSERT INTO Store (retailer_id, name, email, phone, location, contact_info) VALUES
(1, 'RetailMart Central', 'central@retailmart.com', '9998887777', 'Central Plaza, Cityville', 'Manager: Rajesh, +91-9998887777'),
(2, 'SuperSupply Express', 'express@supersupply.com', '8887776666', 'Express Lane, Townburg', 'Manager: Simran, +91-8887776666');

-- RetailerStore
INSERT INTO RetailerStore (retailer_id, store_id, supply_terms) VALUES
(1, 1, 'Weekly supply'),
(2, 2, 'Bi-weekly supply');

-- RetailerGlobal
INSERT INTO RetailerGlobal (retailer_id, product_id, supply_price) VALUES
(1, 1, 25.00),
(2, 2, 15.00);

-- StoreInventory
INSERT INTO StoreInventory (store_id, product_id, quantity, restock_level) VALUES
(1, 1, 200, 20),
(2, 2, 150, 15);

-- User
INSERT INTO User (name, email, phone, address, password_hash) VALUES
('Alice', 'alice@example.com', '9012345678', '1 Park Avenue, Cityville', 'hash1'),
('Bob', 'bob@example.com', '9023456789', '2 Lake Road, Townburg', 'hash2');

-- UserOrder
INSERT INTO UserOrder (user_id, store_id, total_amount, delivery_address, payment_method) VALUES
(1, 1, 70.00, '1 Park Avenue, Cityville', 'ONLINE'),
(2, 2, 40.00, '2 Lake Road, Townburg', 'COD');

-- OrderDescription
INSERT INTO OrderDescription (order_id, product_id, quantity, price, discount) VALUES
(1, 1, 2, 35.00, 0),
(2, 2, 2, 20.00, 0);

-- OrderHistory (manually simulate one completed order)
INSERT INTO OrderHistory (order_id, user_id, store_id, order_date) VALUES
(1, 1, 1, NOW());

-- UserPayment
INSERT INTO UserPayment (user_id, store_id, order_id, amount, payment_mode, transaction_id) VALUES
(1, 1, 1, 70.00, 'UPI', 'TXN123ABC'),
(2, 2, 2, 40.00, 'COD', 'TXN456DEF');

-- StorePayment
INSERT INTO StorePayment (store_id, retailer_id, amount, mode, transaction_id) VALUES
(1, 1, 5000.00, 'BANK_TRANSFER', 'STPAY123'),
(2, 2, 4000.00, 'CASH', 'STPAY456');

-- RetailerPayment
INSERT INTO RetailerPayment (retailer_id, product_id, amount, payment_method, transaction_id) VALUES
(1, 1, 2500.00, 'UPI', 'RPAY123'),
(2, 2, 1500.00, 'CARD', 'RPAY456');

-- StoreRating
INSERT INTO StoreRating (store_id, user_id, rating, review) VALUES
(1, 1, 5, 'Great experience and fast delivery'),
(2, 2, 4, 'Good service but packaging can improve');

-- UserWishlist
INSERT INTO UserWishlist (user_id, product_id) VALUES
(1, 2),
(2, 1);

-- UserCart
INSERT INTO UserCart (user_id, product_id, quantity) VALUES
(1, 2, 1),
(2, 1, 2);

-- Coupon
INSERT INTO Coupon (code, discount_percentage, valid_from, valid_till, description) VALUES
('SAVE10', 10.00, NOW(), DATE_ADD(NOW(), INTERVAL 30 DAY), 'Get 10% off on your next order'),
('FREESHIP', 100.00, NOW(), DATE_ADD(NOW(), INTERVAL 15 DAY), 'Free shipping on orders above ₹500');

-- AppliedCoupon
INSERT INTO AppliedCoupon (user_id, order_id, coupon_id) VALUES
(1, 1, 1),
(2, 2, 2);
