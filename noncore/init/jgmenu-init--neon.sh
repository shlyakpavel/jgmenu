# This shell script fragment is designed to be sourced by jgmenu-init.sh

add_search_box () {
cat >~/.config/jgmenu/prepend.csv <<'EOF'
@rect,action,10,10,180,25,3,left,top,#666666 15,#000000 0,content
@search,action,10,10,180,25,3,left,top,#666666 90,#222222 3,Type to search...
EOF
}

setup_tint2_neon_theme () {
	pgrep tint2 >/dev/null  || return
	printf "%b\n" "Do you wish to create a tint2 config file to match this menu"
	printf "%b" "WARNING: Your current tint2rc will over-written [yN]"
	read answer
	if test "$answer" = "y" || test "$answer" = "Y"
	then
		cp -f "${JGMENU_EXEC_DIR}"/tint2rc.neon ~/.config/tint2/tint2rc
		restart_tint2
	fi
}

setup_theme () {
	add_search_box
	setup_tint2_neon_theme
}