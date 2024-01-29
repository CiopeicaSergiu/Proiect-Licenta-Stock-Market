use licenta;
drop table askPrice;
CREATE TABLE askPrice(
    id int not null, 
    stockName varchar(255) not null,
    quantity MEDIUMINT not null,
    price FLOAT (10, 3) not null
);
insert into askPrice(id, stockName, quantity, price) values (1, "goog", 100, 17283.11505862919);

commit;