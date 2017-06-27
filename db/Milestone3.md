Nelson Mitchell, Jordan Dick, Samuel Eubanks, Theodore Wise, Mahalia Evans

For Tower Trouble™ we use a mySQL database to track highscores over the internet. To begin, it has one table, scores, and 3 columns: id, user, and score. 'id' is an auto-incrementing primary key that allows us to track more than one score per user, user is a string field for the name of the person the score belongs to and score stores their score. To connect with the database we use MySQL Connector/C++.


