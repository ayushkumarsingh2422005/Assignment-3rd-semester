use dbms_course;
ALTER DATABASE dbms_course SET MULTI_USER;
show tables;
SELECT * FROM instructor;
CREATE VIEW faculty AS SELECT id, name, dept_name FROM instructor;
SELECT * FROM faculty;
INSERT INTO faculty VALUES (20051, "xyz", "Physics");

CREATE VIEW CSinstructors AS SELECT * FROM instructor WHERE dept_name="Comp. Sci.";
SELECT * FROM CSinstructors;

INSERT INTO CSinstructors VALUES(23130, "Dinesh", "Comp. Sci.", 170000);


-- 3)
SELECT id, avg(
        CASE
            WHEN grade LIKE "A%" THEN 10
            WHEN grade LIKE "B%" THEN 8
            WHEN grade LIKE "C%" THEN 6
            WHEN grade LIKE "D%" THEN 4
            WHEN grade LIKE "F%" THEN 0
            ELSE NULL
        END
    ) AS CPI
FROM takes
GROUP BY
    id;

-- 4)
INSERT INTO
    section
VALUES (
        'CS-101',
        '1',
        'Summer',
        2017,
        'Painter',
        514,
        'B'
    );

SELECT room_number
FROM section
GROUP BY
    semester,
    YEAR,
    room_number,
    time_slot_id
HAVING
    count(*) > 1;

-- 5)
CREATE VIEW faculty AS SELECT id, name, dept_name FROM instructor;

-- 6)
CREATE VIEW CSInstructor AS
SELECT *
FROM instructor
WHERE
    dept_name = "Comp. Sci.";

-- 7)
INSERT INTO
    CSInstructor
VALUES (
        "99999",
        "Dinesh",
        "Comp. Sci.",
        220000
    );