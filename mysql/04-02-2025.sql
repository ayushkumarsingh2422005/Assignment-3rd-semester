use dbms_course;
select * from takes;
select * from student;

-- Q1 
SELECT 
    s.id
FROM
    student AS s
        LEFT OUTER JOIN
    takes AS t ON s.id = t.id
WHERE
    t.id IS NULL;
    
-- Q2 
SELECT 
    dept_name
FROM
    student AS s
        LEFT OUTER JOIN
    advisor AS a ON s.id = a.s_id
WHERE
    a.s_id IS NULL;
    
-- Q3
insert into course(course_id, title, dept_name, credits) values("CS-001", "Weekly Seminar", "Comp. Sci.", 0);

ALTER TABLE course MODIFY credits NUMERIC(2,0) CHECK (credits >= -1);
select * from course;