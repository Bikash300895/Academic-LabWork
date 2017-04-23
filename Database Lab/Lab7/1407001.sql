set serveroutput on


drop table student;

create table student(
	roll int,
	sub1 int,
	sub2 int,
	sub3 int,
	cg1 number(3,2),
	cg2 number(3,2),
	cg3 number(3,2),
	cgpa number(3,2),
	remarks varchar(30)
);


declare
	i number;
	j number;
	roll students.roll%type;
	sub1 students.sub1%type;
	sub2 students.sub1%type;
	sub3 students.sub1%type;
	cg1 students.cg1%type;
	cg2 students.cg1%type;
	cg3 students.cg1%type;

	cgpa students.cgpa%type;
	remarks students.cgpa%type;


begin
	i:= 0;
	j:= 0;

	for i in 0 .. 10
	Loop
		roll:= i+1;
		sub1:= &Subjcet1;
		sub2:= &Subject2;
		sub3:= &Subject3;

		if sub1>80 then
			cg1 := 4.00;

		elsif sub1>70 then
			cg1 := 3.75;

		elsif sub1>60 then
			cg1 := 3.5;

		else 
			cg1 = 3.25;

		end if;


		if sub2>80 then
			cg2 := 4.00;

		elsif sub2>70 then
			cg2 := 3.75;

		elsif sub2>60 then
			cg2 := 3.5;

		else 
			cg2 = 3.25;

		end if;


		if sub3>80 then
			cg3 := 4.00;

		elsif sub3>70 then
			cg3 := 3.75;

		elsif sub3>60 then
			cg3 := 3.5;

		else 
			cg3 = 3.25;

		end if;


		cgpa := (cg1 + cg2 + cg3) / 3;

		if cgpa>3.75 then
			remarks := 'Dean Award';
		elsif cgpa > 3.00 then
			remarks := '1st Class';
		else
			remarks:='No remarks';

		insert into student values(roll, sub1, sub2, sub3, cg1, cg2, cg3, cgpa, remarks);

	end loop;

	select id into j
	from students where ( students.cgpa = (select max(cgps) from students) and students.cgpa>3.75);

	if j>0 then
	 	UPDATE students
		SET remarks = 'Gold madel'
		WHERE students.id = j; 
	end if;

end;
/


