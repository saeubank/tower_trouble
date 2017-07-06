CREATE DATABASE tower is not exists;
USE tower;
CREATE TABLE if not exists `Players` (
 `Player` integer NOT NULL AUTO_INCREMENT,
 `Score` integer NOT NULL AUTO_INCREMENT);
INSERT INTO 'Players'('Player', 'Score') VALUES ('$Name', '$Score');
UPDATE 'Players';
