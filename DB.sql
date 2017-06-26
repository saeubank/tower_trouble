CREATE DATABASE tower is not exists;
USE tower;
CREATE TABLE if not exists `Players` (
 `Player Name` varchar(40) not null auto_increment,
 `Score` blob not null,
 primary key (`Names`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=7;
INSERT INTO 'Players'('Name', 'Score', 'Levels Completed') VALUES ('$Name', '$Score', '$LS');
UPDATE 'Players';
