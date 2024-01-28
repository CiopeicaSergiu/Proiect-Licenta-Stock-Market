use licenta;
drop table accounts;
CREATE TABLE accounts(
    id_user int not null, 
    fund_name varchar(255) not null,
    funds FLOAT (13, 3) not null,
    last_transaction DATE not null 
);

--insert into accounts(id_user, fund_name, funds, last_transaction) values (1, "test", 12345.123, curdate());
select @userId := id from users where username = "Sergiu";
insert into accounts(id_user, fund_name, funds, last_transaction) values (@userId, "test", 12345.123, curdate());
commit;
