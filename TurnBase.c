#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#define PROGRESS_BAR_SIZE 40

void print_n_chars(int n, int c) {
    while (n-- > 0) putchar(c);
}

void display_progress_bar(int p) {
    putchar('\r');
    putchar('[');
    print_n_chars(PROGRESS_BAR_SIZE * p / 100, '|');
    print_n_chars(PROGRESS_BAR_SIZE - PROGRESS_BAR_SIZE * p / 100, ' ');
    putchar(']');
    printf("Loading Please Wait");
}

//Class

struct Class
{
    char ClassName[10];
    float MaxHp;
    float currentHp;
    int ATK;
    int SpecialSkill;
};

struct Class Name[3] =
{
    {"Tank",4000,4000,250,4},
    {"Mage",2800,2800,250,4},
    {"SwordMan",3500,3500,300,3}
};

//Boss

struct BossClass
{
    char  BossName[10];
    float MaxHp;
    float currentHp;
    int ATK;
    int SpecialSkill;
};

struct BossClass BossName[2] =
{
    {"Pyromancer",3500,3500,200,8},
    {"Cyromancer",4000,4000,300,7}
};

//detail

int currentTurn = 0 ;
int BosscurrentTurn = 0 ;

void ClassDetail(struct Class info)
{
    printf("ClassName : %s \n",info.ClassName);
    printf("MaxHP : %.2f \n",info.MaxHp);
    printf("ATK : %d \n",info.ATK);
    printf("NumSpecialTurn : %d \n",info.SpecialSkill);
}

void DisplayPlayerStatus(struct Class PlayerInfo)
{
    printf(" [%s]\n",PlayerInfo.ClassName);
    printf(" %.2f / %.2f\n",PlayerInfo.currentHp,PlayerInfo.MaxHp);
    printf(" ATK : %d\n",PlayerInfo.ATK);

    if(PlayerInfo.SpecialSkill-currentTurn <= 0)
    {
        printf(" Turn countdown for active special skill : 0");
    }
    else
    {
        printf(" Turn countdown for active special skill : %d",PlayerInfo.SpecialSkill-currentTurn);
    }
}

void DisplayBossStatus(struct BossClass BossInfo)
{
    printf(" [%s]\n",BossInfo.BossName);
    printf(" %.2f / %.2f\n",BossInfo.currentHp,BossInfo.MaxHp);
    printf(" ATK : %d\n",BossInfo.ATK);

    if(BossInfo.SpecialSkill-BosscurrentTurn <= 0)
    {
        printf(" Turn countdown for active special skill : 0");
    }
    else
    {
        printf(" Turn countdown for active special skill : %d",BossInfo.SpecialSkill-BosscurrentTurn);
    }
    
    
};

char pyro[]={'P','y','r','o','m','a','n','c','e','r'};
char cyro[]={'C','y','r','o','m','a','n','c','e','r'};

int main()
{
    int classChoose;
    char classConfirm;
    int ChoiceConfirm;
    int Heal = 3;
    int BossHeal =3;
    char PlayerName[10];
    boolean Defend = FALSE;

    system("cls");

    printf("Welcome to Simple Turn-Base game\n");
    printf("Entering the game");

    for(int i=0;i<3;i++)
    {
        Sleep(200);
        printf(". ");
    }

    for(int i=0;i<100;i++)
    {
        display_progress_bar(i);
        Sleep(20);
    }

    ChooseCharacter:{
    system("cls");

    printf("[Choose your Character] \n");
    printf("1.Tank\n");
    printf("2.Mage\n");
    printf("3.Swordman\n");
    printf("Enter class number here : ");

    scanf(" %d",&classChoose);

    if(classChoose <= 0 || classChoose >=4)
    {
        goto ChooseCharacter;
    }

    system("cls");

    ConfirmClass:{
    switch (classChoose)
    {
        case 1: ClassDetail(Name[classChoose-1]); 
                printf("\nConfirm your character(y/n) : ");

                scanf("%c",&classConfirm);

                switch (classConfirm)
                {
                    case 'y':  system("cls"); printf("You Choose %s!",Name[classChoose-1].ClassName);
                        break;
                
                    case 'n' : goto ChooseCharacter;
                        break;

                    default: system("cls"); goto ConfirmClass;
                        break;
                }
                break;

        case 2: ClassDetail(Name[classChoose-1]); 
                printf("\nConfirm your character(y/n) : ");

                scanf("%c",&classConfirm);

                switch (classConfirm)
                {
                    case 'y':  system("cls"); printf("You Choose %s!",Name[classChoose-1].ClassName);
                        break;
                
                    case 'n' : goto ChooseCharacter;
                        break;

                    default: system("cls"); goto ConfirmClass;
                        break;
                }
                break;

        case 3: ClassDetail(Name[classChoose-1]); 
                printf("\nConfirm your character(y/n) : ");

                scanf("%c",&classConfirm);

                switch (classConfirm)
                {
                    case 'y': system("cls"); printf("You Choose %s!",Name[classChoose-1].ClassName);
                        break;
                
                    case 'n' : goto ChooseCharacter;
                        break;
                    default: system("cls"); goto ConfirmClass;
                        break;
                }
                break;
    }

    printf("\nEnter your name : ");
    scanf(" %s",PlayerName);
    system("cls");
    printf("Your first enemy! ");

    for(int i=0;i<10;i++)
    {
        Sleep(200);
        printf("%c",pyro[i]);
    }

    printf("\nPreparing");

    for(int i=0;i<5;i++)
    {
        Sleep(150);
        printf(". ");
    }
    
    }

    while(Name[classChoose-1].currentHp > 0 || BossName[0].currentHp > 0)
    {
        system("cls");

        currentTurn++;
        BosscurrentTurn++;
        DisplayBossStatus(BossName[0]);
        printf("\n\n");
        printf("\t\tYour Turn\n");
        printf("\n\n");
        printf(" %s",PlayerName);
        DisplayPlayerStatus(Name[classChoose-1]);
        printf("\n  1.Attack\t\t2.Defense");
        printf("\n  3.Skill");

        if(currentTurn >= Name[classChoose-1].SpecialSkill)
        {
            printf("(Ready)");
        }
        else
        {
           printf("(Not Ready)");
        }

        printf("\t4.Heal (%d left)\n",Heal);

        Choice:{
        int Skill;
        scanf("%d",&Skill);
        switch (Skill)
        {
            case 1: if(Defend)
                    {
                        BossName[0].currentHp = BossName[0].currentHp - (Name[classChoose-1].ATK/2);
                        printf("You deal %d damage to %s ",Name[classChoose-1].ATK/2,pyro);
                        Defend = FALSE;
                        if(BossName[0].currentHp <=0)
                        {
                            BossName[0].currentHp = 0;
                        }
                    }
                    else
                    {
                        BossName[0].currentHp = BossName[0].currentHp - Name[classChoose-1].ATK;
                        printf("You deal %d damage to %s ",Name[classChoose-1].ATK,pyro);
                        if(BossName[0].currentHp <=0)
                        {
                            BossName[0].currentHp = 0;
                        }
                    }
                    break;

            case 2: printf("You are defending Reduce damage recieve");
                    Defend = TRUE;
                    break;

            case 3: if(currentTurn >= Name[classChoose-1].SpecialSkill)
                    {
                        printf("You use ");
                        switch (classChoose)
                        {
                            case 1: printf("Smash!");
                                    BossName[0].currentHp = BossName[0].currentHp - (Name[classChoose-1].ATK*2);
                                    if(BossName[0].currentHp <=0)
                                    {
                                        BossName[0].currentHp = 0;
                                    }
                                    break;
                            case 2: printf("ThunderBolt!");
                                    BossName[0].currentHp = BossName[0].currentHp - (Name[classChoose-1].ATK*2);
                                    if(BossName[0].currentHp <=0)
                                    {
                                        BossName[0].currentHp = 0;
                                    }
                                    break;
                            case 3: printf("Slash!");
                                    BossName[0].currentHp = BossName[0].currentHp - (Name[classChoose-1].ATK*2);
                                    if(BossName[0].currentHp <=0)
                                    {
                                        BossName[0].currentHp = 0;
                                    }
                                    break;
                        }
                        printf(" deal %d to %s",(Name[classChoose-1].ATK*2),pyro);
                        currentTurn = 0;
                    }
                    else
                    {
                        printf("It's  not ready!");
                        goto Choice;
                    }
                    break;
            
            case 4: if(Heal > 0)
                    {
                        Name[classChoose-1].currentHp = Name[classChoose-1].currentHp +  ((Name[classChoose-1].MaxHp*10)/100);
                        if(Name[classChoose-1].currentHp > Name[classChoose-1].MaxHp)
                        {
                            Name[classChoose-1].currentHp = Name[classChoose-1].MaxHp;
                        }
                        printf("You restore %.0f HP",((Name[classChoose-1].MaxHp*10)/100));
                        Heal--;
                        if(Heal<=0)
                        {
                            Heal = 0;
                        }
                    }
                    else
                    {
                        printf("No Heal left\n");
                        goto Choice;
                    }
                    
                    break;
            
        }
        if(Name[classChoose-1].currentHp <= 0)
        {
           Sleep(1000);
           system("cls");
           printf("\nYou Lose!");
           break;
        }
        if(BossName[0].currentHp <= 0)
        {
            Sleep(1000);
            system("cls");
            printf("\nYou Win!");
            break;
        }
        Sleep(1000);
        system("cls");
        DisplayBossStatus(BossName[0]);
        printf("\n\n");
        printf("\t\tEnemy Turn\n");
        printf("\n\n");
        printf(" %s",PlayerName);
        DisplayPlayerStatus(Name[classChoose-1]);
        for(int i=0; i<5;i++)
        {
            Sleep(200);
        }
        int BossSkill;
         if(BossHeal <=0)
        {
            BossSkill=(rand() % 3)+1;
        }
        else
        {
            BossSkill=(rand() % 4)+1;
        }
        printf("\n\n");
        switch (BossSkill)
        {
             case 1: if(Defend)
                    {
                        Name[classChoose-1].currentHp = Name[classChoose-1].currentHp - (BossName[0].ATK/2);
                        printf("%s deal %d damage to %s ",pyro,BossName[0].ATK/2,PlayerName);
                        Defend = FALSE;
                        if(Name[classChoose-1].currentHp <= 0)
                        {
                            Name[classChoose-1].currentHp = 0;
                        }
                    }
                    else
                    {
                        Name[classChoose-1].currentHp = Name[classChoose-1].currentHp - BossName[0].ATK;
                        printf("%s deal %d damage to %s ",pyro,BossName[0].ATK,PlayerName);
                        if(Name[classChoose-1].currentHp <= 0)
                        {
                            Name[classChoose-1].currentHp = 0;
                        }
                    }
                    break;

            case 2: printf("%s are defending Reduce damage recieve",BossName[0].BossName);
                    Defend = TRUE;
                    break;

            if(BossSkill == 3)
            {
            case 3: if(BosscurrentTurn >= BossName[0].SpecialSkill)
                    {
                        printf("%s use ",BossName[0].BossName);
                        printf("Pyroblast!");
                        Name[classChoose-1].currentHp = Name[classChoose-1].currentHp - (BossName[0].ATK*2);
                        if(Name[classChoose-1].currentHp <= 0)
                        {
                            Name[classChoose-1].currentHp = 0;
                        }
                        printf(" deal %d to %s",(BossName[0].ATK*2),PlayerName);
                        BosscurrentTurn = 0;
                    }
                    else
                    {
                        if(Defend)
                        {
                            Name[classChoose-1].currentHp = Name[classChoose-1].currentHp - (BossName[0].ATK/2);
                            printf("%s deal %d damage to %s ",pyro,BossName[0].ATK/2,PlayerName);
                            if(Name[classChoose-1].currentHp <= 0)
                            {
                                Name[classChoose-1].currentHp = 0;
                            }
                            Defend = FALSE;
                    }
                        else
                        {
                            Name[classChoose-1].currentHp = Name[classChoose-1].currentHp - BossName[0].ATK;
                            printf("%s deal %d damage to %s ",pyro,BossName[0].ATK,PlayerName);
                            if(Name[classChoose-1].currentHp <= 0)
                            {
                                Name[classChoose-1].currentHp = 0;
                            }
                        }
                    }
                    break;
            }
            case 4: BossName[0].currentHp = BossName[0].currentHp + ((BossName[0].MaxHp*10)/100);
                    if(BossName[0].currentHp > BossName[0].MaxHp)
                    {
                        BossName[0].currentHp = BossName[0].MaxHp;
                    }
                    printf("%s restore %.0f HP",BossName[0].BossName,((BossName[0].MaxHp*10)/100));
                    BossHeal--;
                    break;
        }
        Sleep(1000);
        }

    }
    printf("\nPreparing for last boss\n");
    printf("Restoring you HP and Status");
    for(int i=0;i<3;i++)
    {
        Sleep(1000);
        printf(". ");
    }
    Name[classChoose-1].currentHp = Name[classChoose-1].MaxHp;
    Heal = 3;
    BossHeal = 3;
    Defend = FALSE;
    currentTurn = 0;
    BosscurrentTurn = 0;
    Sleep(1000);
    system("cls");
    printf("Last Boss!");
    for(int i=0;i<10;i++)
    {
        Sleep(200);
        printf("%c",cyro[i]);
    }
    
    printf("\nPreparing");
    for(int i=0;i<5;i++)
    {
        Sleep(150);
        printf(". ");
    }
    
    }
    while(Name[classChoose-1].currentHp > 0 || BossName[1].currentHp > 0)
    {
        system("cls");
        currentTurn++;
        BosscurrentTurn++;
        DisplayBossStatus(BossName[1]);
        printf("\n\n");
        printf("\t\tYour Turn\n");
        printf("\n\n");
        printf(" %s",PlayerName);
        DisplayPlayerStatus(Name[classChoose-1]);
        printf("\n  1.Attack\t\t2.Defense");
        printf("\n  3.Skill");
        if(currentTurn >= Name[classChoose-1].SpecialSkill)
        {
            printf("(Ready)");
        }
        else
        {
           printf("(Not Ready)");
        }
        printf("\t4.Heal (%d left)\n",Heal);
        Choice1:{
        int Skill;
        scanf("%d",&Skill);
        switch (Skill)
        {
            case 1: if(Defend)
                    {
                        BossName[1].currentHp = BossName[1].currentHp - (Name[classChoose-1].ATK/2);
                        printf("You deal %d damage to %s ",Name[classChoose-1].ATK/2,cyro);
                        Defend = FALSE;
                        if(BossName[1].currentHp <=0)
                        {
                            BossName[1].currentHp = 0;
                        }
                    }
                    else
                    {
                        BossName[1].currentHp = BossName[1].currentHp - Name[classChoose-1].ATK;
                        printf("You deal %d damage to %s ",Name[classChoose-1].ATK,cyro);
                        if(BossName[1].currentHp <=0)
                        {
                            BossName[1].currentHp = 0;
                        }
                    }
                    break;

            case 2: printf("You are defending Reduce damage recieve");
                    Defend = TRUE;
                    break;

            case 3: if(currentTurn >= Name[classChoose-1].SpecialSkill)
                    {
                        printf("You use ");
                        switch (classChoose)
                        {
                            case 1: printf("Smash!");
                                    BossName[1].currentHp = BossName[1].currentHp - (Name[classChoose-1].ATK*2);
                                    if(BossName[1].currentHp <=0)
                                    {
                                        BossName[1].currentHp = 0;
                                    }
                                    break;
                            case 2: printf("ThunderBolt!");
                                    BossName[1].currentHp = BossName[1].currentHp - (Name[classChoose-1].ATK*2);
                                    if(BossName[1].currentHp <=0)
                                    {
                                        BossName[1].currentHp = 0;
                                    }
                                    break;
                            case 3: printf("Slash!");
                                    BossName[1].currentHp = BossName[1].currentHp - (Name[classChoose-1].ATK*2);
                                    if(BossName[1].currentHp <=0)
                                    {
                                        BossName[1].currentHp = 0;
                                    }
                                    break;
                        }
                        printf(" deal %d to %s",(Name[classChoose-1].ATK*2),cyro);
                        currentTurn = 0;
                    }
                    else
                    {
                        printf("It's  not ready!");
                        goto Choice1;
                    }
                    break;
            
            case 4: if(Heal > 0)
                    {
                        Name[classChoose-1].currentHp = Name[classChoose-1].currentHp +  ((Name[classChoose-1].MaxHp*10)/100);
                        if(Name[classChoose-1].currentHp > Name[classChoose-1].MaxHp)
                        {
                            Name[classChoose-1].currentHp = Name[classChoose-1].MaxHp;
                        }
                        printf("You restore %.0f HP",((Name[classChoose-1].MaxHp*10)/100));
                        Heal--;
                        if(Heal<=0)
                        {
                            Heal = 0;
                        }
                    }
                    else
                    {
                        printf("No Heal left\n");
                        goto Choice1;
                    }
                    
                    break;
            
        }
        if(Name[classChoose-1].currentHp <= 0)
        {
           Sleep(1000);
           printf("\nYou Lose!");
           break;
        }
        if(BossName[1].currentHp <= 0)
        {
            Sleep(1000);
            printf("\nYou Win!");
            break;
        }
        Sleep(1000);
        system("cls");
        DisplayBossStatus(BossName[1]);
        printf("\n\n");
        printf("\t\tEnemy Turn\n");
        printf("\n\n");
        printf(" %s",PlayerName);
        DisplayPlayerStatus(Name[classChoose-1]);
        for(int i=0; i<5;i++)
        {
            Sleep(200);
        }
        int BossSkill;
         if(BossHeal <=0)
        {
            BossSkill=(rand() % 3)+1;
        }
        else
        {
            BossSkill=(rand() % 4)+1;
        }
        printf("\n\n");
        switch (BossSkill)
        {
             case 1: if(Defend)
                    {
                        Name[classChoose-1].currentHp = Name[classChoose-1].currentHp - (BossName[1].ATK/2);
                        printf("%s deal %d damage to %s ",cyro,BossName[0].ATK/2,PlayerName);
                        Defend = FALSE;
                        if(Name[classChoose-1].currentHp <= 0)
                        {
                            Name[classChoose-1].currentHp = 0;
                        }
                    }
                    else
                    {
                        Name[classChoose-1].currentHp = Name[classChoose-1].currentHp - BossName[1].ATK;
                        printf("%s deal %d damage to %s ",cyro,BossName[1].ATK,PlayerName);
                        if(Name[classChoose-1].currentHp <= 0)
                        {
                            Name[classChoose-1].currentHp = 0;
                        }
                    }
                    break;

            case 2: printf("%s are defending Reduce damage recieve",BossName[1].BossName);
                    Defend = TRUE;
                    break;

            if(BossSkill == 3)
            {
            case 3: if(BosscurrentTurn >= BossName[1].SpecialSkill)
                    {
                        printf("%s use ",BossName[1].BossName);
                        printf("Pyroblast!");
                        Name[classChoose-1].currentHp = Name[classChoose-1].currentHp - (BossName[1].ATK*2);
                        if(Name[classChoose-1].currentHp <= 0)
                        {
                            Name[classChoose-1].currentHp = 0;
                        }
                        printf(" deal %d to %s",(BossName[1].ATK*2),PlayerName);
                        BosscurrentTurn = 0;
                    }
                    else
                    {
                        if(Defend)
                        {
                            Name[classChoose-1].currentHp = Name[classChoose-1].currentHp - (BossName[1].ATK/2);
                            printf("%s deal %d damage to %s ",cyro,BossName[1].ATK/2,PlayerName);
                            if(Name[classChoose-1].currentHp <= 0)
                            {
                                Name[classChoose-1].currentHp = 0;
                            }
                            Defend = FALSE;
                    }
                        else
                        {
                            Name[classChoose-1].currentHp = Name[classChoose-1].currentHp - BossName[1].ATK;
                            printf("%s deal %d damage to %s ",cyro,BossName[1].ATK,PlayerName);
                            if(Name[classChoose-1].currentHp <= 0)
                            {
                                Name[classChoose-1].currentHp = 0;
                            }
                        }
                    }
                    break;
            }
            case 4: BossName[1].currentHp = BossName[1].currentHp + ((BossName[1].MaxHp*10)/100);
                    if(BossName[1].currentHp > BossName[1].MaxHp)
                    {
                        BossName[1].currentHp = BossName[1].MaxHp;
                    }
                    printf("%s restore %.0f HP",BossName[1].BossName,((BossName[1].MaxHp*10)/100));
                    BossHeal--;
                    break;
        }
        Sleep(1000);
        if(BossName[0].currentHp == 0 && BossName[1].currentHp == 0)
        {
            printf("\n!Congrantulation !\n");
            printf("You beat our game\n");
            printf("Thanks for playing");
        }
        }
    }
}



