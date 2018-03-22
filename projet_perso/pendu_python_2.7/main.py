import random;
import os;

# print("hello world");
fo = open("./dico/liste_francais.txt", 'r');
x = 0;
nb_line = 0;
all_line = fo.read();
v = 0;
# line = [];
for v in all_line :
	if v == '\n' :
		nb_line += 1;
# recup ligne choicis;
x = random.randint(0, nb_line);
line = all_line.split("\n");
word_valid = 0;
while word_valid != 1 :
	# word_valid == 0;
	x = random.randint(0, nb_line);
	word = line[x];
	for carac in word :
		# print "ascii == %d" % ord(carac);
		if (ord(carac) >= 65 and ord(carac) <= 90) or (ord(carac) >= 97 and ord(carac) <= 122) or ord(carac) == 13:
			word_valid = 1
			# print "mots valide :%s" % word;
		else :
			word_valid = -1;
			# print "mots invalide :%s" % word;
			break ;

word_len = len(word) - 1;
word_cacher = '_' * word_len;
word_cacher = list(word_cacher)
choice = 0;
while choice == 0 :
	print "le mot fait %d caractere !" % word_len;
	print "%s" % word_cacher;
	first_letter = raw_input("entrer 5 lettre :");
#  verification de la rentrer du joueur;
	if len(first_letter) != 5 :
		print "vous n'avez pas rentrer le bon nombre de lettre";
	elif len(first_letter) == 5 :
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
				break ;
# print type(word_cacher)
letter_place = 0;


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
# print ("le mot a trouver est :\n>>>>>>>>>>>>>>>>%s<<<<<<<<<<<<<<<<<<" % word_cacher);
# debut game
status = 1;
# first_letter = (list)first_letter;
action = 6;
good = 0;
pos = 0;
# word_len = len(word) - 1;
letter_user = '';
while (status == 1) :
	nb_action = 0;
	while (word_len > 0) :
		pos = 0;
		good = 0;
		os.system('clear')
		print (">>>>>>>>>>>>>>>>%s<<<<<<<<<<<<<<<<<<" % word_cacher);
		# print "line choisi = %s" % word;
		print "il reste encore %d coup." % action;
		print "et il te reste %d lettre(s) a trouver\n" % word_len;

		if (nb_action > 0) :
			print "precedent coup : %s" % letter_user;
		letter_user = '';
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
	if (action > 0) :
		print "bien jouer tu a trouver le mots cacher.";
	print ("la mots cacher etait :\n>>>>>>>>>>>>>>>>%s<<<<<<<<<<<<<<<<<<" % word);
	# confirmation = raw_input("Veux tu rejouer ?? (y/n) :");
	# if (confirmation == 'n' or confirmation == 'N') :
	print "Bonne journee et a bientot !";
	exit();		

# # check ocurence
# 						if word[letter_user] == 0 or word_cacher[letter_user] != 0 :
# 							break ;
# 						count_nb_letter += 1;
# # ajout a word_cacher
# 					first_letter[] = letter_user;
# 					word_cacher[letter_place] = letter_user;
# 					word_len -= 1;
# 					good = 1;
# 					break ;
# 				letter_place += 1;
# 			print action;
# 			if (good == 0) :
# 				action -= 1;
# 				print "La lettre ne se trouve pas dans le mot, retente ta chnce ! :)";
# 			else :
# 				good = 0;
# 				print "bien jouer :D";


# print word_cacher ;

# etat_game = 0;
# while (etat_game == 1) :


	# print("FAIL :(");
