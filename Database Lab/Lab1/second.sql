drop table test;
create table test(
id number(3),
name varchar(20),
mark number(3,2)
);

insert into test (id, name, mark) values (1,'abc',8.32);
insert into test (id, name, mark) values (2,'def',8.32);
insert into test (id, name, mark) values (3,'ghi',8.32);

describe test;

select * from test;
select * from test where id=2;
select name from test where id=2;
