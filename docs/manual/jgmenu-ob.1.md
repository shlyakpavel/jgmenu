% JGMENU-OB(1)  
% Johan Malm  
% 23 April, 2018  

# NAME

jgmenu-ob - convert openbox menu data to jgmenu flavoured CSV  

# SYNOPSIS

`jgmenu_run ob` \[\-\-tag=<*tag*>] \[\-\-cmd=<*cmd*> | <*file*>]  

# DESCRIPTION

`jgmenu_run ob` coverts openbox XML menu data to jgmenu flavoured  
CSV. If no <*file*> or --cmd=<*cmd*> is specified,  
~/.config/openbox/menu.xml will be used if it exists.  

# OPTIONS

<*file*>
:   specify openbox XML file.  

\--cmd=<*cmd*>
:   specify command to produce openbox XML menu data.  

\--tag=<*tag*>
:   specify menu element id value in XML file i.e.:  
       <*menu id="root-menu" label="Openbox 3"*>  
       If unset, "root-menu" is used as this is the default in  
       openbox's menu.xml.  

# EXAMPLES

This program is designed to be run from jgmenu by settings  
`csv_cmd = ob` in the configuration file (jgmenurc).  

It can also be run directly from the command line like this:  

    jgmenu_run ob | jgmenu --simple

    jgmenu --csv-cmd="jgmenu_run ob"
