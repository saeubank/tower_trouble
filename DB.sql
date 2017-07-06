CREATE DATABASE tower is not exists;
USE tower;
CREATE TABLE if not exists 'Players' (
 'Player' integer NOT NULL AUTO_INCREMENT,
 'Score' integer NOT NULL AUTO_INCREMENT);
INSERT INTO 'Players' ('Player', 'Score') VALUES (1, 1000);
INSERT INTO 'Players' ('Player', 'Score') VALUES (2, 900);
INSERT INTO 'Players' ('Player', 'Score') VALUES (3, 250);
INSERT INTO 'Players' ('Player', 'Score') VALUES (4, 70);
INSERT INTO 'Players' ('Player', 'Score') VALUES (5, 30);
# INSERT INTO 'Players'('Player', 'Score') VALUES ('$Name', '$Score');
UPDATE 'Players';
