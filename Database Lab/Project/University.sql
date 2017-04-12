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



-- Inserting data
insert into student values(1407001, 'bikash', 3.27);
insert into course values('CSE3120', 'Database', '1.5');


-- Varifying data
select * from student;
select * from course;



-- Cleaning database
drop table course;
drop table student;
