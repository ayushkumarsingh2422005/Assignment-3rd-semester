create table if not exists classroom(
    building varchar(15),
    room_number varchar(7),
    capacity numeric(4,0),
    primary key (building, room_number)
);

create table if not exists department(
    dept_name varchar(20),
    building varchar(15),
    budget numeric(12,2) check(budget > 0),
    primary key(dept_name)
);

create table if not exists course(
    course_id varchar (7),
    title varchar(50),
    dept_name varchar(20),
    credits numeric(2,0) check(credits > 0),
    primary key(course_id),
    foreign key(dept_name) references department(dept_name) on delete set null
);

create table if not exists instructor(
    id varchar(5),
    name varchar(20) not null,
    dept_name varchar(20),
    salary numeric(8,2) check(salary > 29000),
    primary key(id),
    foreign key(dept_name) references department(dept_name) on delete set null
);

create table section(
	course_id varchar(8),
	sec_id varchar(8),
	semester varchar(6) check (semester in("Fall", "Winter", "Spring", "Summer")),
	year numeric (4,0) check (year > 1701 and year < 2100),
	building varchar(15),
	room_number varchar(7),
	time_slot_id varchar(4),
	primary key (course_id, sec_id, semester, year),
    foreign key (course_id) references course(course_id) on delete cascade,
    foreign key (building, room_number) references classroom(building, room_number) on delete set null
);

create table teaches(
	id varchar(5),
	course_id varchar (8),
	sec_id varchar (8),
	semester varchar (6),
	year numeric (4,0),
	primary key(id, course_id, sec_id, semester, year),
	foreign key(course_id, sec_id, semester, year) references section(course_id, sec_id, semester, year) on delete cascade
);

create table student(
	id varchar (5),
	name varchar (20) not null,
    dept_name varchar (20),
	tot_cred numeric (3,0) check(tot_cred >= 0),
	primary key (id),
	foreign key (dept_name) references department(dept_name) on delete set null
);

create table takes(
	id varchar (5),
	course_id varchar (8),
	sec_id varchar (8),
	semester varchar (6),
	year numeric (4,0),
	grade varchar (2),
	primary key (id, course_id, sec_id, semester, year),
	foreign key (course_id, sec_id, semester, year) references section(course_id, sec_id, semester, year) on delete cascade,
    foreign key (id) references student(id) on delete cascade
);

create table advisor(
	s_id varchar (5),
	i_id varchar (5),
	primary key (s_id),
	foreign key (i_id) references instructor(id) on delete set null,
    foreign key (s_id) references student(id) on delete cascade
);

create table prereq(
	course_id varchar(8),
	prereq_id varchar(8),
	primary key (course_id, prereq_id),
	foreign key (course_id) references course(course_id) on delete cascade,
    foreign key (prereq_id) references course(course_id)
);

create table timeslot(
	time_slot_id varchar (4),
	day varchar (1) check (day in ("M", "T", "W", "R", "F", "S", "U")),
	start_time time,
    end_time time,
    primary key (time_slot_id, day, start_time)
);