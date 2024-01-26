use licenta;
drop table buy;
CREATE TABLE buy(
    id_user MEDIUMINT not null, 
    id int not null auto_increment, 
    stockName varchar(255) not null,
    quantity MEDIUMINT not null,
    price FLOAT (10, 3) not null,
    primary key (id)
);
insert into buy(id_user, stockName, quantity, price) values (1, "test", 75, 10.57);

commit;