SHOW DATABASES;

USE dbms_course;

SHOW TABLES;

SELECT * FROM section;

SELECT course_id, sec_id, semester, year, count(sec_id) FROM takes
GROUP BY course_id, sec_id, semester, year;

-- Q1

SELECT course_id, sec_id, semester, year, COUNT(sec_id) as student_count 
FROM takes
GROUP BY course_id, sec_id, semester, year
HAVING COUNT(sec_id) >= ALL (
    SELECT COUNT(sec_id)
    FROM takes
    GROUP BY course_id, sec_id, semester, year
);

-- Q2
-- Find all sections that had the maximum enrollment (along with the enrollment),using a subquery.
SELECT * FROM takes
WHERE (course_id, sec_id, semester, year) IN (
    SELECT course_id, sec_id, semester, year
    FROM takes
    GROUP BY course_id, sec_id, semester, year
    HAVING COUNT(sec_id) >= ALL (
        SELECT COUNT(sec_id)
        FROM takes
        GROUP BY course_id, sec_id, semester, year
    )
);

-- 3. Show all sections with their enrollment counts (including sections with 0 enrollment)
-- Method 1: Using LEFT JOIN
SELECT s.course_id, s.sec_id, s.semester, s.year, COUNT(t.ID) as student_count
FROM section s
LEFT JOIN takes t ON 
    s.course_id = t.course_id AND 
    s.sec_id = t.sec_id AND 
    s.semester = t.semester AND 
    s.year = t.year
GROUP BY s.course_id, s.sec_id, s.semester, s.year;

-- Method 2: Using scalar subquery
SELECT s.course_id, s.sec_id, s.semester, s.year,
    (SELECT COUNT(*) 
     FROM takes t 
     WHERE t.course_id = s.course_id 
        AND t.sec_id = s.sec_id 
        AND t.semester = s.semester 
        AND t.year = s.year) as student_count
FROM section s;

-- Q4 Find all courses whose identifier starts with the string "CS-1"
SELECT * FROM course
WHERE course_id LIKE 'CS-1%';

-- O6 Insert each instructor as a student, with tot_creds = 0, in the same department
INSERT INTO student (ID, name, dept_name, tot_cred)
SELECT ID, name, dept_name, 0
FROM instructor
WHERE instructor.ID NOT IN (SELECT ID FROM student);

-- Q7 . Now delete all the newly added "students" above (note: already existing students who happened to have tot_creds = 0 should not get deleted)
DELETE FROM student
WHERE ID IN (
    SELECT ID
    FROM instructor
    WHERE instructor.name = student.name AND 
    instructor.dept_name = student.dept_name
);

SELECT * FROM instructor;
SELECT * FROM student;
