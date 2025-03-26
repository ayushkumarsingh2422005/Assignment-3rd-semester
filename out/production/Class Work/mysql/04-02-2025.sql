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

select department.dept_name 
from department 
where department.budget>(select budget from department where dept_name='history');

SELECT course_id,ID FROM takes GROUP BY ID,course_id HAVING COUNT(course_id)>=2;

select student.id,student.name
from student 
where student.name like 'd%' and student.dept_name ='history'
and student.id not in(select takes.id from takes
join course on takes.course_id=course.course_id
where course.dept_name='music'
GROUP BY takes.id
HAVING COUNT(takes.course_id) >= 5
);


WITH se AS (    
SELECT course_id, sec_id, year, semester, count(*) as num    
FROM takes    
GROUP BY course_id, sec_id, year, semester    
),    
me AS (
SELECT max(num) AS max_num FROM se
)
SELECT s.course_id, s.sec_id, s.year, s.semester, s.num    
FROM se s, me m    
WHERE s.num = m.max_num;

SELECT i.id, i.name  
FROM instructor i  
WHERE NOT EXISTS (  
    SELECT 1  
    FROM teaches t  
    JOIN takes ta ON t.course_id = ta.course_id  
    AND t.sec_id = ta.sec_id  
    AND t.semester = ta.semester  
    AND t.year = ta.year  
    WHERE t.id = i.id  
    AND ta.grade = 'a'  
);

SELECT i.id, i.name  
FROM instructor i  
WHERE NOT EXISTS (    
    SELECT 1  
    FROM teaches t  
    JOIN takes ta ON t.course_id = ta.course_id   
                 AND t.sec_id = ta.sec_id   
                 AND t.semester = ta.semester   
                 AND t.year = ta.year  
    WHERE t.id = i.id  
    AND ta.grade = 'A'
);





