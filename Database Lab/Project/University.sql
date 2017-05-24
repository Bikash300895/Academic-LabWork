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
insert into course values('CSE3100', 'Web Promgramming', '1.5', 'CSE');

insert into enrollment values(1407001, 'CSE3120', 3.75);
insert into enrollment values(1407001, 'CSE3100', 4.00);

insert into teacher values(555, 'MR Y', 'CSE');

insert into course_teacher values ('CSE3120', 555);


-- Varifying data
select * from student;
select * from course;
select * from enrollment;
select * from department;
select * from teacher;
select * from course_teacher;



-- PL/SQL

-- Get max cgpa among the students
set serveroutput on
declare
	max_cgpa student.cgpa%type;

begin
	select max(cgpa) into max_cgpa
	from student;
	dbms_output.put_line('Max cgpa : ' || max_cgpa);

end;
/


-- Show the grade according to (IF condition)

set serveroutput on
declare
	gpa enrollment.grade%type;

begin
	select grade into gpa
	from enrollment
	where student_id = 1407001 and course_id='CSE3120';

	if(gpa = 4) then
		dbms_output.put_line('A+');

	elsif(gpa = 3.75) then
		dbms_output.put_line('A');
	else
		dbms_output.put_line('A-');

	end if;

end;
/

-- Show grade of all subject with loop

set serveroutput on
declare
	cursor enroll_cursor is select student_id, grade from enrollment;
	student_record enroll_cursor%rowtype;
	i number := 1;

begin
	open enroll_cursor;

		loop

			fetch enroll_cursor into student_record;
			exit when i > 2;

			dbms_output.put_line(student_record.student_id|| ' ' || student_record.grade);
			i := i+1;

		end loop;

	close enroll_cursor;
end;
/


create or replace procedure INSEERTSTUDENT (id IN NUMBER, name IN VARCHAR2, cgpa IN number) is
	begin
		insert into student values(id, name, cgpa);   
	end;
	/

begin
	INSEERTSTUDENT(1407002,'Tushar Pranto',3.10);
	INSEERTSTUDENT(1407003,'Hasib iqbal',3.15);
	INSEERTSTUDENT(1407004,'Tawhid jwarder',3.22);
	INSEERTSTUDENT(1407005,'Mehedi hasan',3.16);
end;
/


select * from student;

-- Cleaning database
drop table course_teacher;
drop table teacher;
drop table enrollment;
drop table course;
drop table department;
drop table student;
