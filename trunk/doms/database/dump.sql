-- Doms DB DUMP
-- Last modified: 13/05/06 15:40

-- Settings
SET client_encoding = 'SQL_ASCII';

-- Cleaning...

drop table doms_clinic cascade;
drop table doms_employee cascade;
drop table doms_pacients cascade;
drop table doms_persons cascade;
drop table doms_procedure cascade;
drop table doms_sickness cascade;
drop table doms_specialist cascade;
drop table doms_speciality cascade;
drop table dt_users cascade;
drop table doms_cite cascade;
drop table doms_pacient_sickness;

drop domain doms_genre_domain cascade;
drop domain doms_civil_state cascade;
drop domain doms_cite_state cascade;
drop domain doms_confirmation cascade;
drop domain doms_id_document_type cascade;

-- Creating...
CREATE DOMAIN doms_genre_domain as int check(value in (0, 1));
CREATE DOMAIN doms_civil_state as int check(value in (0, 1, 2, 3));
CREATE DOMAIN doms_cite_state as int check(value in (0,1,2,3,4,5));
CREATE DOMAIN doms_confirmation as int check(value in (0,1,2));
CREATE DOMAIN doms_id_document_type as int check(value in (0,1,2,3));

create table dt_users (
	login character varying(20) PRIMARY KEY,
	password character varying(30),
	permissions character varying(10) -- Secuencia de bits, cada implementacion debe decidir que significa cada bit
);

insert into dt_users values ( 'testuser', 'pass', '111111111' );

create table doms_persons (
	name character varying(50),
	lastName character varying(50),
	genre doms_genre_domain,
	civilState doms_civil_state,
	bornDate DATE,
	bornCity character varying(30),
	departament character varying(30), 
	idDocument character varying(15) PRIMARY KEY,
	idDocumentType doms_id_document_type,
	address character varying(30), 
	currentCity character varying(30),
	phone character varying(10),
	cellular character varying(10), 
	email character varying(70) check( email like '%@%.%' )
);

create table doms_pacients (
	idDocument character varying(15) references doms_persons(idDocument) on delete cascade on update cascade,
-- 	clinicHistory character varying(15) PRIMARY KEY,
 	occupation character varying(20),
	workPhone character varying(10),
	responsiblePerson character varying(50),
	responsibleRelationchip character varying(50),
	responsiblePhone character varying(10),
	responsibleOccupation character varying(80),
	referenceName character varying(50),
	referenceRelationchip character varying(20),
	referenePhone character varying(10),
	referenceOccupation character varying(20),
	eps character varying(20),
	PRIMARY KEY(idDocument)
);

create table doms_employee(
	idDocument character varying(15) references doms_persons(idDocument) on delete cascade on update cascade,
	charge character varying(50)
);

create table doms_speciality (
	name character varying(20), 
	idSpeciality character varying(6) PRIMARY KEY
);

create table doms_specialist (
	idDocument character varying(15) references doms_persons(idDocument) on delete cascade on update cascade,
	idSpecialist character varying(6) PRIMARY KEY,
	idSpeciality character varying(6) references doms_speciality(idSpeciality )
);


create table doms_procedure (
	idProcedure character varying(6) PRIMARY KEY,
	idSpeciality character varying(6) references doms_speciality(idSpeciality), 
	description text,
	cost int
);

create table doms_cite (
	idSpecialist character varying(6) references doms_specialist(idSpecialist),
	date DATE,
	hour TIME,
	idDocument character varying(15) references doms_persons(idDocument),
	confirmationPerson character varying(50),
	confirmation doms_confirmation,
	state doms_cite_state,
	idProcedure character varying(6) references doms_procedure( idProcedure)
);


create table doms_sickness (
	sicknessName character varying(30),
	idSickness character varying(30) PRIMARY KEY
);

create table doms_pacient_sickness(
	idDocument character varying(15) references doms_persons(idDocument),
	idSickness character varying(30) references doms_sickness(idSickness)
);


create table doms_clinic (
	name character varying(50),
	address character varying(50),
	phone character varying(10),
	seat character varying(50)
);
-- 
-- Fgeneral(
-- 	fecha DATE, 
-- 	historia_clinica references Paciente(historia_clinica), 
-- 	idEspecialista references Especialista(idEspecialista), 
-- 	motivo_ de_consulta TEXT, 
-- 	remitido_por TEXT
-- 	);
-- 
-- Fendodoncia(
-- 	idFormulario character varying(6)
-- 	historia_clinica references Paciente(historia_clinica), 
-- 	motivo_ de_consulta TEXT,
-- 	idEvolucion1 references EvolucionEndo1,
-- 	idEvolucion2 references EvolucionEndo2, PRIMARY KEY Paco
-- );
-- 
-- 
-- 
-- EvolucionEndo1(
-- 	 idEvolucion1 PRIMARY KEY character varying(6),
-- 	fecha DATE,
-- 	diente character varying(10),
-- 	dx_pulpar character varying(20),
-- 	dx_perapical character varying(20),
-- 	dx_rx character varying(20),
-- )
-- 
-- EvolucionEndo2(
--  	idEvolucion2 PRIMARY KEY character varying(6),
-- 	fecha DATE,
-- 	diente character varying(10),
-- 	dx character varying(20),
-- 	conducto character varying(20),
-- 	conomet character varying(20),
-- 	delta character varying(20),
-- 	lap character varying(20)	
-- 	);
-- 
-- Fortodoncia(
-- 	idFormulario PRIMARY KEY character varying(6)
-- 	historia_clinica references Paciente(historia_clinica), 
-- 	antecedentes character varying(20),
-- 	dentincion character varying(20),
-- 	perfil character varying(20),
-- 	cara character varying(20),
-- 	dientes_retenidos character varying(20),
-- 	dientes_ausentes character varying(20),
-- 	dientes_erupcionar character varying(20),
-- 	atm character varying(20),
-- 	labios character varying(20),
-- 	idEvolucionOrto references EvolucionOrto(idEvolucionOrto),
-- 	);
-- 
-- EvolucionOrto(
-- 	idEvolucionOrto PRIMARY KEY character varying(6),
-- 	dx TEXT,
-- 	pronostico TEXT,
-- 	tratamiento TEXT,
-- 	mecanica_tratamiento	 TEXT
-- 	);
-- 
-- 
-- 
-- HojaBlanco(
-- 	idHojaBlanco PRIMARY KEY character varying(6)
-- |	texto TEXT,
-- 	);



