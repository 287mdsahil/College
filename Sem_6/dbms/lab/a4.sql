--1
create table emp(emp_code char(5),dept_code char(5),basic numeric);
insert into emp values('SAH','SYST',6000);
insert into emp values('BIK','FIN',7000);

declare
    id emp.emp_code%TYPE;
    dcode emp.dept_code%TYPE;
    bs emp.basic%TYPE;
begin
    id := 'BIK';
    select dept_code,basic into dcode,bs from emp where emp_code=id;
    dbms_output.put_line(dcode || ' '  || bs);
exception
    when NO_DATA_FOUND
    then dbms_output.put_line('Not found');
end;


--2
create table department(
    dept_code char(5) primary key,
    name char(20)
);

create table employee(
    emp_code char(5) primary key,
    dept_code char(5),
    name char(20),
    address char(20),
    basic numeric,
    foreign key (dept_code) references department(dept_code)
);

insert into department values('SYS','Systems');
insert into department values('FIN','Finance');
insert into department values('HR','Human Resources');

insert into employee values('sah01','SYS','SAHIL','Dubrajpur',6000);
insert into employee values('bik02','FIN','BIKRAM','Durgapur',8000);

declare
    l_parentnotfound exception;
    ecode employee.emp_code%TYPE :='iri09';
    dcode employee.dept_code%TYPE :='HD';
    ename employee.name%TYPE :='IRIN';
    eaddr employee.address%TYPE :='KOLKATA';
    ebasic employee.basic%TYPE :=7000;
    PRAGMA EXCEPTION_INIT(l_parentnotfound, -2291);
begin
    insert into employee values(ecode,dcode,ename,eaddr,ebasic);
exception
    when DUP_VAL_ON_INDEX
	then dbms_output.put_line('Non unique id');
	when l_parentnotfound
	then dbms_output.put_line('Invalid department id');
end;

--4
declare
    rec employee%ROWTYPE;
begin
    for rec in ( 
        select * from employee 
        order by basic desc
        fetch first 5 rows only 
    )
    loop
        dbms_output.put_line(rec.name);
    end loop;
end;
