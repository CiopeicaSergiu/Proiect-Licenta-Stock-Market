use licenta;
drop table users;
CREATE TABLE users(
    id int not null auto_increment, 
    username varchar(255) not null,
    pass varchar(255) not null,
    primary key (id)
);

insert into users(username, pass) values ("sergiu", "123456");

commit;