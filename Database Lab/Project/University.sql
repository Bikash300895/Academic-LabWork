-- Creating table
create table student(
	id  	int NOT NULL,
	name	varchar(50)	not null,
	cgpa 	number(3,2),
	primary key(id)
);

create table course(
	course_id 	varchar(10)		not null,
	title 		varchar(50)		not null,
	credits		number(3,2),
	primary key (course_id)
);


create table enrollment(
	student_id		int 			not null,
	course_id		varchar(10) 	not null,
	grade			number(3,2),
	foreign key		(student_id) 	references	student(id),
	foreign key 	(course_id)		references	course(course_id)
);


create table department(
	id 				varchar(3) 		not null,
	name			varchar(50) 	not null,
	dept_head		varchar(20)  	not null,
	primary key(id)
);


alter table course add (department varchar(3),
						foreign key(department) references department(id));

create table teacher(
	id 			int 			not null,
	name 		varchar(50) 	not null,
	department	varchar(3)		not null,
	primary key	(id),
	foreign key	(department)	references	department(id)
);

create table course_teacher(
	course_id 	varchar(10) 	not null,
	teacher_id	int 			not null,
	foreign key	(course_id)		references		course(course_id),
	foreign key (teacher_id)	references		teacher(id)
);


-- Inserting data
insert into student values(1407001, 'bikash', 3.27);
insert into department values('CSE', 'Computer science and engineering', 'Mr. X');
insert into course values('CSE3120', 'Database', '1.5', 'CSE');
insert into enrollment values(1407001, 'CSE3120', 0.00);
insert into teacher values(555, 'MR Y', 'CSE');
insert into course_teacher values ('CSE3120', 555);


-- Varifying data
select * from student;
select * from course;
select * from enrollment;
select * from department;
select * from teacher;
select * from course_teacher;



-- Cleaning database
drop table course_teacher;
drop table teacher;
drop table enrollment;
drop table course;
drop table department;
drop table student;
