use licenta;
drop table buy;
CREATE TABLE buy(
    id int not null auto_increment, 
    stockName varchar(255) not null,
    quantity MEDIUMINT not null,
    price FLOAT (10, 3) not null,
    primary key (id)
);

insert into buy(stockName, quantity, price) values ("test", "75", "10.57");

commit;