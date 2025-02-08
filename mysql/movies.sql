-- Creating tables
CREATE TABLE actors (
    AID INT PRIMARY KEY,
    name VARCHAR(255) NOT NULL
);

CREATE TABLE movies (
    MID INT PRIMARY KEY,
    title VARCHAR(255) NOT NULL
);

CREATE TABLE actor_role (
    MID INT,
    AID INT,
    rolename VARCHAR(255) NOT NULL,
    PRIMARY KEY (MID, AID, rolename),
    FOREIGN KEY (MID) REFERENCES movies(MID),
    FOREIGN KEY (AID) REFERENCES actors(AID)
);

-- Inserting data into actors table
INSERT INTO actors (AID, name) VALUES
(1, 'Charlie Chaplin'),
(2, 'Ayush Kumar Singh'),
(3, 'Robert Downey Jr.'),
(4, 'Scarlett Johansson'),
(5, 'Leonardo DiCaprio'),
(6, 'Morgan Freeman');

update actors set name = "Ayush Kumar Singh" where AID = 2;

select * from actors;

-- Inserting data into movies table
INSERT INTO movies (MID, title) VALUES
(101, 'Modern Times'),
(102, 'The Great Dictator'),
(103, 'Iron Man'),
(104, 'The Avengers'),
(105, 'Inception'),
(106, 'Shawshank Redemption');

select * from movies;

-- Inserting data into actor_role table
INSERT INTO actor_role (MID, AID, rolename) VALUES
(101, 1, 'Little Tramp'),
(102, 1, 'Adenoid Hynkel'),
(102, 1, 'Jewish Barber'),
(103, 3, 'Tony Stark'),
(104, 3, 'Iron Man'),
(104, 4, 'Black Widow'),
(105, 5, 'Dom Cobb'),
(106, 6, 'Ellis Redding');

select * from actor_role;

-- Query to list all movies in which Charlie Chaplin has acted, along with the number of roles he had
SELECT m.title, COUNT(ar.rolename) AS role_count
FROM movies m
JOIN actor_role ar ON m.MID = ar.MID
JOIN actors a ON ar.AID = a.AID
WHERE a.name = 'Charlie Chaplin'
GROUP BY m.title;

-- Query to list all actors who have not acted in any movie
SELECT a.name
FROM actors a
LEFT JOIN actor_role ar ON a.AID = ar.AID
WHERE ar.AID IS NULL;

-- Query to list names of actors along with movie titles they have acted in (show null for actors without movies)
SELECT a.name, m.title
FROM actors a
LEFT JOIN actor_role ar ON a.AID = ar.AID
LEFT JOIN movies m ON ar.MID = m.MID;
