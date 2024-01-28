use licenta;
drop table owned;
CREATE TABLE owned(
    id int not null auto_increment, 
    stockName varchar(255) not null,
    quantity MEDIUMINT not null,
    price FLOAT (10, 3) not null,
    primary key (id)
);
insert into owned(id_user, stockName, quantity, price) values (1, "test", 75, 10.57);

commit;