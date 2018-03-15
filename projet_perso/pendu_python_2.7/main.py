import random;
import os;

fo = open("./dico/liste_francais.txt", 'r');
x = 0;
nb_line = 0;
all_line = fo.read();
v = 0;
for v in all_line :
	if v == '\n' :
		nb_line += 1;
# recup ligne choicis;
x = random.randint(0, nb_line);
line = all_line.split("\n");
word_valid = 0;
while word_valid != 1 :
	x = random.randint(0, nb_line);
	word = line[x];
	for carac in word :
		if (ord(carac) >= 65 and ord(carac) <= 90) or (ord(carac) >= 97 and ord(carac) <= 122) or ord(carac) == 13:
			word_valid = 1
		else :
			word_valid = -1;
			break ;

## fin parsing
## choix de trois lettre par user
word_len = len(word) - 1;
word_cacher = '_' * word_len;
word_cacher = list(word_cacher)
choice = 0;
while choice == 0 :
	print "le mot fait %d caractere !" % word_len;
	print "%s" % word_cacher;
	first_letter = raw_input("entrer 3 lettre :");
#  verification de la rentrer du joueur;
	if len(first_letter) != 3 :
		print "vous n'avez pas rentrer le bon nombre de lettre";
	elif len(first_letter) == 3 :
		choice = -1;
		while (choice == -1) :
			confirmation = raw_input("vous avez donner : >%s< vous confirmer ?\n(Y/n) : " % first_letter);
			print "choix == %c" % confirmation;
			if confirmation == 'y' or confirmation == 'Y':
				print "bon courrage alors";
				choice = 1;
				break ;
			elif confirmation != "n" and confirmation != "y" :
				confirmation = raw_input("(y/n)");
			elif confirmation == "n" or confirmation == "N" :
				choice = 0;
letter_place = 0;
#### fin choix des trois lettre
#### compare lettre entre avec le mots a trouver
print word_cacher;
word = list(word);
first_letter = list(first_letter);
for letter_word in word :
	print "la lettre du mots est :%c\n" % letter_word;
	for letter_user in first_letter :
		if letter_user == letter_word :
			word_cacher[letter_place] = letter_user;
			word_len -= 1;
	letter_place += 1;

## les trois lettres on ete placer si elle se trouvais dans le mot
## debut game
status = 1;
action = 6;
good = 0;
pos = 0;
while (status == 1) :
	nb_action = 0;
	while (word_len > 0) :
		pos = 0;
		good = 0;
		letter_user = '';
		os.system('clear')
		print (">>>>>>>>>>>>>>>>%s<<<<<<<<<<<<<<<<<<" % word_cacher);
		print "il reste encore %d coup." % action;
		print "et il te reste %d lettre(s) a trouver\n" % word_len;

		if (nb_action > 0) :
			print "precedent coup : %s" % letter_user;
		letter_user = raw_input("entrer une lettre : ");
		nb_action += 1;
# check word
		if letter_user != "" :
			for check_in_word in word :
				if (check_in_word == letter_user) :
					for check_letter_in_cacher in word_cacher :
						if (check_letter_in_cacher == letter_user and good == 0) :
							good = -1;
							break ;
					if (good != -1) :
						good = 1;
						word_cacher[pos] = letter_user;
						word_len -= 1;
				pos += 1;
			if (good == -1 or good == 0):
				action -= 1;
		if (action == 0):
			print "echec";

			break ;
	# fin du jeux
	if (action > 0) :
		print "bien jouer tu a trouver le mots cacher.";
	print ("la mots cacher etait :\n>>>>>>>>>>>>>>>>%s<<<<<<<<<<<<<<<<<<" % word);
	print "Bonne journee et a bientot !";
	exit();
