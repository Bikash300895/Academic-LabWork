drop table test;
create table test(
id number(3),
name varchar(20),
mark number(3,2)
);
describe test;
insert into test (id, name, mark) values (110,'Hasan',8.32);
insert into test (id, name, mark) values (111,'Masud',15.32);
insert into test (id, name, mark) values (112,'Mfdsud',1.32);
select * from test;