use licenta;
drop table askPrice;
CREATE TABLE askPrice(
    id int not null auto_increment, 
    stockName varchar(255) not null,
    quantity MEDIUMINT not null,
    price FLOAT (10, 3) not null,
    primary key (id)
);
insert into askPrice(stockName, quantity, price) values ("test", 75, 10.57);

commit;