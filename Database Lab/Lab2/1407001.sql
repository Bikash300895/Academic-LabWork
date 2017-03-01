drop table students;

create table students(
	roll number(4),
	name varchar(20),
	enrollment_date date
);


drop table courses;

create table courses (
	c_id varchar(10), 
	c_name varchar(30), 
	year number(1), 
	term number(1)
);

drop table teachers;
create table teachers(t_ID number(4),name varchar(20), joining_date date);



describe students;
describe courses;

alter table students add phone varchar(15);

alter table students modify roll number(7);

alter table courses rename column c_id to c_no;

alter table teachers add designation varchar(50);

describe students;
describe courses;

insert into students values (1, 'Bikash', to_date('12-nov-2016'), '01700000000');

insert into courses values (1, 'database', 3, 1);

insert into teachers values (1, 'MR. X', to_date('12-nov-2016'),'Professor');

select * from students;
select * from courses;
select * from teachers;


drop table Employee;
create table Employee(
	employee_id NUMBER(10) NOT NULL,
	first_name VARCHAR(25) NOT NULL,
	last_name VARCHAR(30) NOT NULL,
	hire_date DATE DEFAULT sysdate
);

describe Employee;
select * from Employee;



insert into Employee values(1, 'bikash', 'roy',to_date('12-nov-2016'));

insert into Employee(employee_id, first_name, last_name) values(2,'bikash','roy'); 

alter table Employee add salary number(10);

insert into Employee(employee_id, first_name, last_name) values(2,'bikash','roy'); 
delete from Employee;
	
alter table Employee modify salary number(9) NOT NULL;