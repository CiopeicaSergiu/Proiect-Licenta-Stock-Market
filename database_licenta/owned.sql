use licenta;
drop table owned;
CREATE TABLE owned(
    id int not null auto_increment,
    id_user int not null,  
    stockName varchar(255) not null,
    quantity MEDIUMINT not null,
    price FLOAT (10, 3) not null,
    buy_date DATE not null, 
    primary key (id)
);

insert into owned(id_user, stockName, quantity, price, buy_date) values (1, "test", 75, 10.57, curdate());
commit;