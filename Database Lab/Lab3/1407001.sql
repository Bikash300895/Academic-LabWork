drop table course_taken;
drop table courses;
drop table students;



create table students(
	roll 		number(7),
	name 		varchar(50) 	not null,
	department 	varchar(10) 	not null,
	primary key(roll)
);

create table courses(
	c_id 		number(7) 	not null,
	primary key	(c_id),
	c_name 		varchar(50) unique,
	year 		number(1) 	check(year>0 and year<5),
	term 		number(1) 	check(term>0 and term<3),
	credit 		number(3,2) default 3.00
);

create table course_taken(
	roll 	number(7) 	not null,
	c_id 	number(10) not null,
	sess	varchar(10) not null,
	FOREIGN KEY (roll) REFERENCES students(roll) on delete cascade 
);

describe students;
describe courses;
describe course_taken;

alter table course_taken add foreign key (c_id) references courses(c_id) on delete cascade;


insert into students values (1407001, 'Bikash', 'cse');
insert into students values (1407002, 'X', 'cse');
insert into students values (1407003, 'Y', 'cse');

insert into courses values (3100, 'IP', 3, 1, 1.5);
insert into courses values (3120, 'SE', 3, 1, 1.5);
insert into courses values (3110, 'DB', 3, 1, 1.5);

insert into course_taken values (1407001, 3100, '2016-2017');
insert into course_taken values (1407001, 3110, '2016-2017');
insert into course_taken values (1407002, 3120, '2016-2017');

select * from students;
select * from courses;
select * from course_taken;

delete from students where roll=1407002;

select * from course_taken where roll=1407001;