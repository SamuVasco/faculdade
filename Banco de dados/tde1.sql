create table proprietario (
	id_proprietario int primary key,
	nome_proprietario varchar(100),
	uf varchar(2),
	dt_nascimento date
);

create table multa (
	id_multa int primary key,
	desc_multa varchar(100),
	artigo varchar(100),
	pontos int,
	valor numeric(10, 2)
);

crate table locali (
	id_local int primary key,
	rodovia varchar(100)
);

create table carro (


);



