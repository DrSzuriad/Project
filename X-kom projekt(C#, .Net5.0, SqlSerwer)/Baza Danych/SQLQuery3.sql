

CREATE DATABASE Projekt_xcom;


Drop TABLE Uczestnik;
Drop TABLE Spotkania;


CREATE TABLE Spotkania (
    Id int not null identity(1, 1) primary key,
    Nazwa varchar(255),
    Opis varchar(255),
    Data_spotkania datetime,
);

CREATE TABLE Uczestnik (
    Id int not null identity(1, 1) primary key,
    Imie varchar(255),
    Nazwisko varchar(255),
    IdSpotkania int not null,
	FOREIGN KEY (IdSpotkania) REFERENCES Spotkania(ID)
);


INSERT INTO Spotkania VALUES ('Spotkanie przyrodnik�w', 'Rozmowa o kwiatkach', '2021-07-01 8:30:00');
INSERT INTO Spotkania VALUES ('Spotkanie pasjonat�w �limak�w', 'Na spotkaniu prowadzone b�d� rozmowy na temat gatunk�w �limk�w wykorzystywanych w medycynie alternatywnej', '2021-09-05 12:45:00');

INSERT INTO Uczestnik VALUES ('Adrzej', 'Wierzba', 10);
INSERT INTO Uczestnik VALUES ('Artur', 'Bukowiecki', 11);
INSERT INTO Uczestnik VALUES ('Pawe�', 'Brzoza', 10);
INSERT INTO Uczestnik VALUES ('Hanna', 'Grom', 10);

Select * from Spotkania;
Select * from Uczestnik;

Select * from Spotkania as s join Uczestnik as u on s.ID=u.IdSpotkania;


SELECT s.Id,s.Nazwa,s.Opis,s.Data_spotkania,ISNULL(Ilo��, 0 ) FROM Spotkania s LEFT JOIN (SELECT u.IdSpotkania, count(IdSpotkania) as Ilo�� FROM Uczestnik as u GROUP BY u.IdSpotkania) u ON s.ID=u.IdSpotkania
