# Password Cracking HW

## Password Results

- [x] alice123: P@ssw0rd
    
Using the rockyou wordlist went pretty quick for this one.

- [x] bob456: W1nt3r22

I used a custom wordlist for bob456 below

```
winter2022
WINTER2022
w1nt3r2022
W1NT3R2022
WINTER2022
2022WINT3R
2022W1nt3r
2022w1nt3r
2022winter
winter
2022
winter22
WINTER22 *
W1NT3R22
22winter
22WINTER
22w1nt3r
w1nt3r22
snowfield22
sn0w22
sn0w2022
sn0wf13ld2022
sn0wf13ld22
SN0WF13LD22
SN0WF13LD2022
football2022
F00TB@LL2022
W1NT3RF00TB@LL2022
F00TB@LL22
w1nt3rf00tb@ll2022
f00tb@llw1nt3r2022
footballfield2022
footballfieldwinter2022
footballsnowfield2022
footbalwinter2022
footballwinter22
footballsnowfield22
fbwinter2022
F00TB@LLW1NT3R22
f00tb@llw1nt3r22
```

Which also works with the ruleset at the bottom and dictionary:

```
// bob456_dict2.txt
winter
```

- [ ] charlie789:

```
autumn
oak
autumnoak
oakforest
autumnfestival
autumnoakfestival
autumnoak
autumnforest
autumnwalk
autumnfall
```
**Using the rulesets below**

- [ ] diana101:

```

```

**Using the rulesets below**

- [ ] edward202: 

```

```

**Using the rulesets below**

- [ ] frank303:

```

```

**Using the rulesets below**

- [x] grace404: Spring88

After a lot of time using the rules with different combinations, I tried this dictionary without rules for grace and got her password quickly:

```
lucky88
Lucky88
Lucky88!
spring88
spring88!
Spring88!
spr1ng88
Spr1ng88
Spr1ng88!
flowers88
flowers88!
Flowers88!
Flowers88
Fl0w3rs88
fl0w3rs88!
flower88
flower88!
fl0w3r88
fl0w3r88!
garden88
Garden88
garden88!
g@rd3n88!
G@rd3n88!
```

![Cracking Grace](https://github.com/isaacdenny/csc3940/blob/master/a1_password_cracking/screenshots/cracking-grace.png)

- [ ] henry505:

Tried to crack henry's with no luck:
![Trying to crack henry](https://github.com/isaacdenny/csc3940/blob/master/a1_password_cracking/screenshots/trying-henry.png)

- [ ] irene606:

No luck with irene either:
![Trying Irene](https://github.com/isaacdenny/csc3940/blob/master/a1_password_cracking/screenshots/trying-irene-and-admins.png)

- [ ] jack707:
- [ ] karen808:
- [ ] admins:
**See above for some of admins attempts screenshot**

## Custom Ruleset

I dove into the john ruleset syntax [here](https://www.openwall.com/john/doc/RULES.shtml) to add leetspeak options quicker and number combinations

```
[List.Rules:Bob]
:
u
l

#leetspeak uppercase
si1 sa@ so0 se3 u
# leetspeak lowercase
si1 sa@ so0 se3 l
#leetspeak capitalized
si1 sa@ so0 se3 c
# leetspeak cap inverted
si1 sa@ so0 se3 C

Az"[0-9][0-9]"
Az"[0-9][0-9]" u Q

Az"[0-9][0-9][0-9]"
Az"[0-9][0-9][0-9]" u Q

Az"[0-9][0-9][0-9][0-9]" Q
Az"[0-9][0-9][0-9][0-9]" u Q

# leetspeak cap inverted 2 numbers
Az"[0-9][0-9]" si1 sa@ so0 se3 C Q
# leetspeak cap 2 numbers
Az"[0-9][0-9]" si1 sa@ so0 se3 c Q
# leetspeak upper 2 numbers
Az"[0-9][0-9]" si1 sa@ so0 se3 u Q
# leetspeak lower 2 numbers
Az"[0-9][0-9]" si1 sa@ so0 se3 l Q

# above^ !
Az"[0-9][0-9]!" si1 sa@ so0 se3 C Q
Az"[0-9][0-9]!" si1 sa@ so0 se3 c Q
Az"[0-9][0-9]!" si1 sa@ so0 se3 u Q
Az"[0-9][0-9]!" si1 sa@ so0 se3 l Q

# above^ 3 numbers
Az"[0-9][0-9][0-9]" si1 sa@ so0 se3 C Q
Az"[0-9][0-9][0-9]" si1 sa@ so0 se3 c Q
Az"[0-9][0-9][0-9]" si1 sa@ so0 se3 u Q
Az"[0-9][0-9][0-9]" si1 sa@ so0 se3 l Q

# above^ !
Az"[0-9][0-9][0-9]!" si1 sa@ so0 se3 C Q
Az"[0-9][0-9][0-9]!" si1 sa@ so0 se3 c Q
Az"[0-9][0-9][0-9]!" si1 sa@ so0 se3 u Q
Az"[0-9][0-9][0-9]!" si1 sa@ so0 se3 l Q

[List.Rules:CSC3940a1-2]
Az"[a-z][a-z][a-z]"
Az"[a-z][a-z][a-z]" C Q
Az"[a-z][a-z][a-z]" u Q
Az"[a-z][a-z][a-z]" si1 sa@ so0 se3 u Q
Az"[a-z][a-z][a-z]" si1 sa@ so0 se3 l Q
Az"[a-z][a-z][a-z]" si1 sa@ so0 se3 c Q
Az"[a-z][a-z][a-z]" si1 sa@ so0 se3 C Q

[List.Rules:Symbols]
# !
Az"!"
Az"!" si1 sa@ so0 se3 Q
Az"!" si1 sa@ so0 se3 C Q
Az"!" si1 sa@ so0 se3 c Q
Az"!" si1 sa@ so0 se3 u Q
Az"!" si1 sa@ so0 se3 l Q

# $
Az"$"
Az"$" si1 sa@ so0 se3 Q
Az"$" si1 sa@ so0 se3 C Q
Az"$" si1 sa@ so0 se3 c Q
Az"$" si1 sa@ so0 se3 u Q
Az"$" si1 sa@ so0 se3 l Q

# #
Az"#"
Az"#" si1 sa@ so0 se3 Q
Az"#" si1 sa@ so0 se3 C Q
Az"#" si1 sa@ so0 se3 c Q
Az"#" si1 sa@ so0 se3 u Q
Az"#" si1 sa@ so0 se3 l Q

[List.Rules:Irene]
c
C
Az"!"
Az"!" c
si1 sa@ so0 se3 ss$ c
Az"!" si1 sa@ so0 se3 c
Az"[0-9][0-9]" Q
Az"[0-9][0-9]" si1 sa@ so0 se3 ss$ Q
Az"[0-9][0-9]" si1 sa@ so0 se3 ss$ c Q
Az"[0-9][0-9]!" Q
Az"[0-9][0-9]!" si1 sa@ so0 se3 ss$ Q
Az"[0-9][0-9]!" si1 sa@ so0 se3 ss$ c Q
Az"[0-9][0-9][0-9]!" si1 sa@ so0 se3 ss$ c Q
```

**The larger rulesets made each session take closer to about 10 minutes**

I had more luck without them

## Reflection

Overall: 3/12 passwords cracked

I cracked a couple passwords using dictionaries based on key words from the user bios and the john default rules `--rules`. Building my own ruleset and diving into the syntax was fun, but didn't yield me anything for the other users (I wrote and rewrote the rulesets MANY times). Appending numbers and using leetspeak helped to build a large-enough password dictionary to crack grace404's and bob456's passwords. While it was painfull to run the rules on the dictionary over and over again without results, it was a really fun experience when I was able to crack a few of them.
