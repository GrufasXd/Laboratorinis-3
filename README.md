Atsisiuntus pateikta aplankalą reikia jį atidaryti programavimo aplinkoje, pvz (VS code).
Programavimo aplinkos terminale parašyti "make -f MakefileVector", "make -f MakefileList", "make -f MakefileDeque" arba "make -f MakefileClass" norint sukompiliuoti atitinkamai, vector, list, deque arba class failus.
Tada parašyti "./main_vector", "./main_list", "./main_deque" arba "./main_class" tam pačiam terminale norint paleisti programą veikiančią su atitinkamais konteineriais.
Jeigu viskas buvo įrašyta teisingai, programa pasileis ir prašys pasirinkti rūšiavimo strategiją - 1, 2 ar 3 kurią lengvai galite pasirinkti paspaudę atitinkamą skaičių. Pasirinkus strategiją galėsite pasirinkti studentų rūšiavimo kriterijų(pagal galutinį pažymių vidurkį, arba pagal medianą) prieš tai parodydama kiek laiko užtruko sukurti failą.
Programa nuskaitys sukurtą failą, surušiuos jį pagal pasirinktą kriterijų ir viską išves į 2 naujus failus vargsai.txt ir galva.txt(galva.txt - rodo kriterijų atitinkančius studentus kurių mediana arba vidurkis yra didesnis arba lygus 5, o vargsai.txt rodys studentus kurių mediana arba vidurkis yra mažesnis už 5) ir lauks kol jūs paspausite "Enter" mygtuką. Kol laukiate galite atsidaryti failus vargsai.txt ir galva.txt ir patikrinti arba apžvelgti rūšiavimą.
Kai programa baigs rūšiuoti paskutinį failą bus rodomas kiek laiko užtruko visas kodas.

Makefile atsisiuntimas - 

1 žingsnis - Įdiekite MinGW paketų tvarkyklę. tai galite padaryti šios nuorodos pagalba https://sourceforge.net/projects/mingw/  ir paspaudę mygtuką "Install"

2 -žingsnis - Nustatykite vietą, kur norite įdiegti MinGW paketų tvarkyklę. Kai naršyklės viršuje rodys, kad siuntimas baigtas, 2 kart paspauskit ant atsisiųsto failo.

3 -žingsnis - Atsidariusiam programos lange spauskite "Install".

4 - žingsnis - Paspausti pasirinkimo laukelį prie kurio parašyta "... also install support for graphical user interface"

5 - žingsnis - Laukti kol atisiųs MinGW.

6 - žingsnis - Eikite į „C“ diską, atidarykite „MinGW“ aplanką ir suraskite „mingw-get.exe“ failą. Nukopijuokite failo vietą.

7 - žingsnis - Apačioje, pradiniame meniu, ieškokite „Environment Variables“ ir atidarykite juos.

8 - žingsnis - Paspauskite „Environment Variables“ mygtuką, kad nustatytumėte kelią aplinkos kintamuosiuose.

9 - žingsnis - Iš „System Variables“ (sistemos kintamųjų) panelės pasirinkite „Path“ ir paspauskite „Edit“ mygtuką.

10 - žingsis - Po to, paspauskite „New“ mygtuką ir įklijuokite nukopijuotą kelią į Path lauką. Tada spauskite „Ok“ mygtuką.

11 - žingsnis: Pradiniame meniu ieškokite „CMD“ ir atidarykite komandų eilutę.

12 - žingsnis - Tada, vykdykite pateiktą komandą, kad įdiegtumėte make į Windows: "mingw-get install mingw32-make".

13 - žingsnis - Patikrinkite make komandos įdiegimą tikrindami jos versiją: "mingw32-make --version" Jeigu po šios komandos matote instaliuotą versiją, vadinasi viską padarėte gerai.

Programas laikas, su sukurtais failais -

<img width="576" alt="irdouasnmd 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/edb2dbe7-1bbd-449b-b648-966e7daa2ec6">

<img width="576" alt="irodumas 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/17c4c376-2d7f-46cd-9083-8928e3d334af">

Failų kūrimas - 

<img width="576" alt="irdoyumas 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/4ee71c75-34d6-4bf6-a0fe-af1afdc12143">

<img width="576" alt="irdoymas 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/d236d610-268d-485c-a9f0-06691dc3f859">

Vector 1 strategijos laikai - 

<img width="786" alt="vector 1 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/83d2abe8-d3be-42fc-8d07-33b6ee4599bf">

<img width="576" alt="vector 1 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/5354322c-06e6-4c78-9908-6787023072c2">

<img width="632" alt="vector 1 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/ffbd03b4-8ecd-4c3d-8222-d22d0c9999ec">

<img width="576" alt="vector 1 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/9104f41e-d8b0-46fb-a77c-900f3088ff32">

Vector 2 strategijos laikai -

<img width="788" alt="vector 2 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/ae99dbb2-fc74-44e1-afd9-2c6045ce0be7">

<img width="674" alt="vector 2 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/d8e8ed3f-c109-4875-96aa-17d045de9954">

<img width="774" alt="vector 2 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/4465c24a-2675-47b6-bcfc-ae88d9805cb5">

<img width="779" alt="vector 2 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/2c680986-1367-41f3-a344-758db8c0a16a">

Vector 3 strategijos laikai -

<img width="818" alt="vector 3 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/a3720b9b-f0ab-49e2-ae88-c1b3b68329d3">

<img width="820" alt="vector 3 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/e767beb9-6dac-489c-9856-2d87f26ba9dd">

List 1 strategijos laikai -

<img width="786" alt="list 1 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/6d5e7ad1-c263-44da-b3d6-215183cb654c">

<img width="576" alt="list 1 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/3b15981e-7475-41e0-91bf-f695e6eedd4b">

<img width="784" alt="list 1 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/bae3df54-0296-440f-a80b-6d5de1e570d5">

<img width="576" alt="list 1 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/17ab3254-cc37-42ae-af4f-1f0f0013b988">

List 2 strategijos laikai - 

<img width="786" alt="list 2 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/a5f827aa-57d3-4da2-963b-d20152c97da9">

<img width="784" alt="list 2 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/8a1ff412-f2fa-4c6b-8e39-3461ccf40412">

<img width="789" alt="list 2 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/fe2a2fa6-d19c-443f-8256-274ee13fcf8d">

<img width="771" alt="list 2 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/b3e66905-f0ff-487e-b4a8-4c17d3a89af7">

List 3 strategijos laikai -

<img width="817" alt="list 3 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/09e3c301-100d-4e70-b1ef-e46aa7b35158">

<img width="819" alt="list 3 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/53b8dc96-8ad7-4e49-879f-b858aa190d1d">

Deque 1 strategijos laikai - 

<img width="787" alt="deque 1 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/adee377f-4fce-441c-b92e-8abf74762d28">

<img width="784" alt="deque 1 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/99aa7557-4be8-4ac6-934b-176d0ab7b3f6">

<img width="788" alt="deque 1 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/86c373bd-9561-4f89-825e-d25cf25bbcce">

<img width="788" alt="deque 1 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/f4654bd2-0b90-45eb-9bf1-af09c6d87050">

Deque 2 strategijos laikai - 

<img width="788" alt="deque 2 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/b4da068f-ccf2-48ed-ac5b-0bb39e5c65dd">

<img width="785" alt="deque 2 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/a08be643-aece-465b-9751-f279591dd3b3">

<img width="793" alt="deque 2 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/57a0c65f-c283-4de0-a171-d028c05aaca4">

<img width="788" alt="deque 2 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/9fa5f018-2ee9-4d3e-a331-5414d1970849">

Deque 3 strategijos laikai - 

<img width="790" alt="deque 3 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/f47af7f0-2e38-4971-af34-508cde8593b0">

<img width="783" alt="deque 3 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/e33c4068-870c-4955-a7e0-43a85cf3ae5c">

<img width="817" alt="deque 3 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/84279e75-daaf-46cd-b054-7206d046e578">

Pirmam pre-release buvo atliekami testai su visais konteineriais tik 1 strategija. 
Šiame pilname release buvo testuojamos papildomai 2 ir 3 strategijos. 2 Visiem konteinerių tipam - tokia pati. 3 strategija - patobulinta versija greitesnės strategijos iš pirmų dviejų pagal konteinerį.
Su list konteineriu buvo patobulinta 2 strategija, o su vector ir deque konteineriais patobulinta 1 strategija.

Sistemos parametrai - 
SSD - SAMSUNG MZNLN256HAJQ-00007
CPU - Intel(R) Core(TM) i7-8565U CPU @ 1.80GHz
Instaliuoti Ramai - 16GB

Versija v.pradinė: Sukurtas main.cpp failas kurį paleidus programa nuskaito vartotojo įvedamus duomenis, t.y. - studentų skaičių, studento vardą, studento pavardę, pažymių kiekį, pažymius priklausančius nuo pažymių kiekio ir egzamino rezultatą. Kai įvedami visų studentų duomenys programa ekrane parodys lentelę kurioje rodomos sklitys - "Pavarde", "Vardas", "Galutinis (Vid. )" (galutinis pažymių vidurkis) ir "Galutinis (Med. )" (pažymių mediana). Galutinis balas ir mediana pateikiami dviejų skaičių po kablelio tikslumu. Stundentų duomenys įvedami naudojant struktūrą ir masyvus.

Versija v0.1: Papildytas main.cpp failas iš v.pradinė versijos. Paleidus programą ekrane pasirodo meniu su pasirinkimais: Viska rasyti ranka - 1 Generuoti tik pazymius - 2 Generuoti ir pazymius ir studentu vardus, pavardes - 3 Baigti darba - 4 Pasirinkus viską rašyti ranka - programos veikimas toks pat kaip ir v.pradinėje versijoje, išskyrus tai, kad programai nereikia iš anksto žinoti kiek yra studentų, nes visi studentų duomenys yra laikomi dinaminėje atmintyje kurią pastoviai didiname po kiekvieno naujo įrašo. Pasirinkus generuoti tik pažymius, programos veikimas toks pat išskyrus tai, kad pažymių pačiam rašyti nereikia. Pasirinkus generuoti ir pažymius ir studentų vardus, pavardes bus viskas generuojama atsitiktinai išskyrus egzamino pažymį. Pasirinkus "Baigti darba" programa rodys visus įvestus studentus. Kaip anksčiau minėjau duomenys yra laikomi dinaminėje atmintyje. Taip pat šioje versijoje buvo sukurtas naujas failas pavadinimu vector.cpp. Jame vykdomi tie patys veiksmai kaip ir atnaujintoje main.cpp failo versijoje išskyrus tai, kad visi masyvai buvo pakeisti į vektorius.

Versija v0.2: Nuo šios versijos buvo atnaujinamas tik vector.cpp failas. Šioje versijoje buvo sukurti 4 nauji failai - kursiokai1.txt (10 tūkst. duom.), kursiokai2.txt (100 tūkst. duom.), kursiokai3.txt (1 mil. duom.) ir outputas.txt (skirtas surušiuotų duomenų įrašymui). Jų struktūra tokia pati. Įdėtas pasirinkimas nuskaityti duomenis iš failo. Paleidus programą matoma lentelė: Ar norite duomenis generuoti / rasyti ranka - 1 Ar norite duomenis skaityti is failo - 2 ir pasirinkus duomenis skaityti iš failo rodoma kita lentelė: Is kurio failo skaityti duomenis? 10k duomenu - 1 100k duomenu - 2 1mil duomenu - 3 Pasirinkus atitinkamą skaičių iš to failo bus skaitomi duomenys. Po šios operacijos bus rodoma kita lentelė: Kaip norite kad butu surusiuoti duomenis? Pagal varda - 1 Pagal pavarde - 2 Galutini pazymiu vidurki - 3 Galutini pagal mediana - 4 Pasirinkus skaičių duomenys bus rušiuojami pagal atitinkamą parametrą. Duomenys faile outputas.txt bus surušiuoti didėjimo tvarka. Po rušiavimo rodoma paskutinė lentelė: Ar duomenis spausdinti ekrane - 1 Ar duomenis spausdint faile - 2 Vėlgi, pasirinkus 1 arba 2, duomenys bus spausdinami ekrane arba faile.

Versija v0.3: Šioje versijoje atsirado 3 nauji failai: funkcijos.cpp, funkcijos.h ir Makefile. funkcijos.h - faile yra funkcijų naudojamų programoje prototipai ir struktūra. funkcijos.cpp - failas sudarytas iš funkcijų realizacijų. Makefile - programos make failas atsakingas už programos paleidimą. vector.cpp buvo atnaujintas, jame liko tik main funkcija. Taip pat programoje kur tikslinga buvo panaudotas išimčių valdymas. Programa kompiliuojama į terminalą rašant žodį "make". Po kompiliavimo programą galima paleisti rašant "./main".

Versija v0.4: Sukurta nauja failų kūrimo funkcija, su kuria sugeneruoti 5 nauji failai - failas1.txt (1 tūkst. duom.), failas2.txt (10 tūkst. duom.), failas3.txt (100 tūkst. duom.), failas4.txt (1 mil. duom.) ir failas5.txt (10 mil. duom.). Sugeneruoti studentai yra grupuojami į vargšiukus ir galvočius (pagal pažymių vidurkį arba medianą - priklausomai nuo vartotojo pasirinkimo) naujos studrus funkcijos pagalba. Jei vidurkis arba mediana (priklausomai nuo pasirinkimo) yra mažesnis nei 5, studentas yra laikomas vargšiuku, o jei didesnis nei 5 - studentas laikomas galvočiumi. Po rūšiavimo, sugrupuoti studentai yra išvedami į 2 naujus failus - vargsai.txt (vargšiukų failas) ir galva.txt (galvočių failas). Taip pat programoje matuojamas laikas - failų kūrimo, duomenų nuskaitymo iš failo, studentų grupavimo į 2 grupes, rašymo į failus, visos programos laikas.

Versija v1.0 - pre release: Sukurti 8 nauji failai: 4 - failai programai veikti su list konteineriu (funkcijosList.cpp, funkcijosList.h, list.cpp, MakefileList) ir kiti 4 - failai programai veikti su deque konteineriu (funkcijosDeque.cpp, funkcijosDeque.h, deque.cpp, MakefileDeque). Šioje versijoje buvo atliekamas greičio testavimas tarp visų 3 konteinerių - vector, list ir deque.

Versija v1.0 - galutinė: Sukurtos 2 naujos funkcijos pademonstruoti 2 naujas studentų dalijimo į 2 kategorijas strategijas: studrus1 ir studrus2. studrus1 strategija - vietoj to, kad saugotumėme studentus 2 konteineriuose (galva ir vargsai), paliekam tik 1 konteinerį - vargsai. Rūšiuodami su šia strategija ir radę vargšiuką - jį dedame į naują vargšų konteinerį ir ištriname iš visų studentų konteinerio. Tada visų studentų konteineryje lieka tik galvočiai. studrus2 strategija - patobulinta greičiausia (pagal konteinerį) strategija. Vector ir Deque atveju buvo patobulintos 1 strategija (studrus), o List atveju patobulinta 2 strategija (studrus1).

Versija v1.1:
Atliktas repozitorijos klonavimas iš v1.0 versijos. Šioje versijoje programoje vietoj struktūros pradėta naudoti klasę. Darytas greičio testavimas tarp programos su struktūra ir programos su klase. Testavimas buvo atliekamas su vektoriumi ir 100 tūkst. bei 1 mil. dydžio failais. Vėliau, testavimas buvo atliekamas ir su optimizavimo "flagais" tarp šių dviejų versijų.

Programos greitis naudojant vektoriu ir struktūrą su pačia greičiausia strategija:

<img width="789" alt="ob 0 struct" src="https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/79c05fac-8af8-4e57-92bb-9d0bef73ff89">

Programos greitis naudojant vektoriu ir klasę su pačia greičiausia strategija:

<img width="788" alt="ob 0 class" src="https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/b4f63e05-643f-4da0-a958-5cbb38853df7">

Lentelė, kurioje nurodomi greičio skirtumai naudojant skirtingas strukturas:

![image_2024-05-31_142854782](https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/20a39760-7091-48a9-8021-72fc413a7029)

1.2 versija:
Realizuoti visi "Rule of five" bei įvesties ir išvesties operatoriai turimai Studentas klasei.
Įvesties ir išvesties operatoriai perdengti funkcijai studrus (taip pat studrus1 ir studrus2), vadinasi duomenys yra vedami iš failų ir po darbo su jais išvedami į failus.
"Rule of five" metodų pavyzdys:

<img width="780" alt="rule of five 1" src="https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/11a4e1a1-9ded-4aff-bfe5-f6fede8b9a93">

<img width="780" alt="rule of five 2" src="https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/c23f64fe-8f16-4a12-8f3c-68e63cbf76d0">

Greičio skirtumai tarp 1.1 versijos klasės ir 1.2 versijos klasės su perdengtais įvesties ir išvesties operatoriais(lyginimai atliekami su 100 tūkst. duomenų failu ir 1mil. duomenų failu):
1.1 versijos klasė:

<img width="788" alt="ob 0 class" src="https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/277ad54a-6090-4ef5-bf40-061ffd734945">

1.2 versijos klasė su perdengtais įvesties ir išvesties operatoriais:

<img width="776" alt="input output test" src="https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/22a873c5-4ddd-4883-80e1-2818b0c2af70">

Visos programos laiko skirtumas tarp šių dviejų versijų:

<img width="576" alt="lentele2" src="https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/e1578099-7367-4f30-ab58-533556e6b833">

Įvesties ir išvesties operatoriai perdengti studrus(studentų rūšiavimo ir skirstymo į 2 grupes) funkcijai. Vadinasi duomenys buvo nuskaitomi ir įrašomi į failus šių operatorių dėka.

1.5 versija:
Sukurta nauja Zmogus klasė, kuri veikia kaip bazinė klasė mūsų sukurtai Studentas klasei. Bazinė klasė Zmogus yra abstrakčioji - vadinasi jos tipo objektų kurti negalima. Po šios klasės sukūrimo buvo testuojama ar veikia Studentas klasės "Rule of five" metodai, bei įvesties ir išvesties operatoriai.
Abstrakčios klasės Zmogus realizacijos įrodymas (žmogaus tipo objektų kurti negalima):

<img width="783" alt="irdoymas kad negalima daryti Zmogus klases objektu" src="https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/b86443fb-510e-4e9a-8564-180856e62109">

Po Zmogus klasės sukūrimo veikiantys "Rule of five" metodai:

<img width="781" alt="rof1" src="https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/76aae102-0d39-4784-94c6-49b2cc92b484">

<img width="780" alt="rof2" src="https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/c51f7b0d-4ea8-4544-b548-130ed90eb1f1">

Patikrinti įvesties ir išvesties metodai po Zmogus klasės sukūrimo:

<img width="780" alt="in out irod po pakeit" src="https://github.com/GrufasXd/Laboratorinis-2/assets/147091694/8a841323-c028-47fc-8d9b-fdfc2caa656a">

v3.0:
Mano Vector konteinerio tikrinimas per funkcijos pavyzdzius:
1. Testuojamas konstruktorius su daug elementu. "Vector<int> v = {8, 4, 5, 9};"
2. Testuojama push_back funkcija. "v.push_back(6);"
3. Testuojamas priskyrimo operatorius. "v[2] = -1;"
4. Testuojama v.size() funkcija. "cout << "Dydis " << v.size() << endl;"
5. Testuojama v.clear() funkcija. "v.clear();"

![image](https://github.com/GrufasXd/Laboratorinis-3/assets/147091694/0a8e42ac-2fb1-482a-bf96-eb5240406539)

Greičio spartos skirtumas tarp mano Vector konteinerio ir std::vector konteinerio naudojant push_back funkciją:

10k elem. -

<img width="777" alt="10k vec" src="https://github.com/GrufasXd/Laboratorinis-3/assets/147091694/b84b72eb-7d5b-454a-8e7c-056450618461">

100k elem. -

<img width="778" alt="100k vec" src="https://github.com/GrufasXd/Laboratorinis-3/assets/147091694/3827d87c-c6d3-4111-9dc6-fdb09b9888ad">

1 mil. elem. - 

<img width="776" alt="1mil vec" src="https://github.com/GrufasXd/Laboratorinis-3/assets/147091694/c2e1e7fd-7e38-43f8-9dde-1f76e8f980ff">

10 mil. elem. - 

<img width="777" alt="10mil vec" src="https://github.com/GrufasXd/Laboratorinis-3/assets/147091694/800c8820-e9ab-4694-a0ef-8bf86fa361f8">

100 mil. elem. - 

<img width="776" alt="100mil vec" src="https://github.com/GrufasXd/Laboratorinis-3/assets/147091694/6327fe1f-2c47-435e-9699-e40f503fa19c">

Perskirstymu skirtumas tarp mano Vector konteinerio ir std::vector :

<img width="778" alt="atminties perskirstymai" src="https://github.com/GrufasXd/Laboratorinis-3/assets/147091694/86c02c7d-ee34-4975-a1b0-a232bbf8a248">

Palyginimas mano Vector konteinerio ir std::vector konteinerio greičio su studrus funkcija :

100k duom. - 

Mano Vector konteineris:

<img width="780" alt="100k faillu mano vec" src="https://github.com/GrufasXd/Laboratorinis-3/assets/147091694/b98c7ea5-badb-49ac-b34a-67fb07bba7b9">

std::vector :

<img width="778" alt="100k std vec" src="https://github.com/GrufasXd/Laboratorinis-3/assets/147091694/2c47980a-b34f-476b-a499-39f32c6a5915">

1mil duom. - 

Mano Vector konteineris:

<img width="766" alt="1 mil mano vec" src="https://github.com/GrufasXd/Laboratorinis-3/assets/147091694/5ae3a2ac-fd00-4aeb-8b65-62ec5b778601">

std::vector :

<img width="777" alt="1mil std vec" src="https://github.com/GrufasXd/Laboratorinis-3/assets/147091694/7bbac212-d364-4413-bd05-e6857209ae08">




