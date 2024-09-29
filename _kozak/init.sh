#!/bin/bash



echo "<< QMK Kozak >>"


eval `qmk env | grep "QMK_HOME"`


# dirs
KOZAK="$QMK_HOME/_kozak"
BUILDS="$KOZAK/builds"



# active board dirs
_keychron="$QMK_HOME/keyboards/keychron/common"
_q0="$QMK_HOME/keyboards/keychron/q0"
_q2="$QMK_HOME/keyboards/keychron/q2"
_q60="$QMK_HOME/keyboards/keychron/q60"
_tempo="$QMK_HOME/keyboards/mode/m60h"
_m0110="$QMK_HOME/keyboards/converter/m0110_usb"
_adb="$QMK_HOME/keyboards/converter/adb_usb"
_portable="$QMK_HOME/keyboards/converter/macintosh_portable"

# custom keymaps
_q0km="$_q0/plus/keymaps/kozak"
_q2km="$_q2/ansi_encoder/keymaps/kozak"
_q60km="$_q60/ansi/keymaps/kozak"
_tempokm="$_tempo/keymaps/kozak"
_m0110km="$_m0110/kozak/keymaps/m0110"
_m0120km="$_m0110/kozak/keymaps/m0110_m0120"
_m0110akm="$_m0110/kozak/keymaps/m0110a"
_m0115km="$_adb/kozak/keymaps/m0115"
_m0115v2km="$_adb/kozak/keymaps/m0115v2"
_m0116km="$_adb/kozak/keymaps/m0116"
_portablekm="$_portable/keymaps/kozak"

# customized keyboards
_q0c="keychron/q0/plus"
_q2c="keychron/q2/ansi_encoder"
_q60c="keychron/q60/ansi"
_tempoc="mode/m60h"
_m0110c="converter/m0110_usb/kozak"
_adbc="converter/adb_usb/kozak"
_portablec="converter/macintosh_portable"

# build filenames
_q0f="keychron_q0_plus_kozak.bin"
_q2f="keychron_q2_ansi_encoder_kozak.bin"
_q60f="keychron_q60_ansi_kozak.bin"
_tempof="mode_m60h_kozak.bin"
_m0110f="converter_m0110_usb_kozak_m0110.hex"
_m0120f="converter_m0110_usb_kozak_m0110_m0120.hex"
_m0110af="converter_m0110_usb_kozak_m0110a.hex"
_m0115f="converter_adb_usb_kozak_m0115.hex"
_m0115v2f="converter_adb_usb_kozak_m0115v2.hex"
_m0116f="converter_adb_usb_kozak_m0116.hex"
_portablef="converter_macintosh_portable_kozak.uf2"


# fs aliases
alias b='open $BUILDS'

# edit aliases
alias keychron='cd $_keychron; e'
alias q0='cd "$_q0"; e'
alias q2='cd "$_q2"; e'
alias q60='cd "$_q60"; e'
alias tempo='cd "$_tempo"; e'
alias m0110='cd "$_m0110"; e'
alias adb='cd "$_adb"; e'
alias portable='cd $_portable; e'

alias ek='cd "$KOZAK"; e'

alias e0='cd $_q0km; e'
alias e2='cd $_q2km; e'
alias e60='cd $_q60km; e'
alias etempo='cd $_tempokm; e'
alias em0110='cd "$_m0110km"; e'
alias em0110a='cd "$_m0110akm"; e'
alias em0115='cd $_m0115km; e'
alias em0115v2='cd $_m0115v2km; e'
alias em0116='cd $_m0116km; e'

# autocorrect aliases
alias ace='e "$KOZAK"/autocorrect_dictionary.txt'

alias acrm_q2='[ -e "$_q2"/ansi_encoder/keymaps/kozak/autocorrect_data.h ] && rm "$_q2"/ansi_encoder/keymaps/kozak/autocorrect_data.h'
alias acrm_q60='[ -e "$_q60"/ansi/keymaps/kozak/autocorrect_data.h ] && rm "$_q60"/ansi/keymaps/kozak/autocorrect_data.h'
alias acrm_tempo='[ -e "$_tempo"/keymaps/kozak/autocorrect_data.h ] && rm "$_tempo"/keymaps/kozak/autocorrect_data.h'
alias acrm_m0115='[ -e "$_adb"/kozak/keymaps/m0115/autocorrect_data.h ] && rm "$_adb"/kozak/keymaps/m0115/autocorrect_data.h'
alias acrm_m0115v2='[ -e "$_adb"/kozak/keymaps/m0115v2/autocorrect_data.h ] && rm "$_adb"/kozak/keymaps/m0115v2/autocorrect_data.h'
alias acrm_m0116='[ -e "$_adb"/kozak/keymaps/m0116/autocorrect_data.h ] && rm "$_adb"/kozak/keymaps/m0116/autocorrect_data.h'
alias acrm_portable='[ -e "$_portable"/keymaps/kozak/autocorrect_data.h ] && rm "$_portable"/keymaps/kozak/autocorrect_data.h'
alias acrm="acrm_q2 && acrm_q60 && acrm_tempo && acrm_m0115 && acrm_m0115v2 && acrm_m0116 && acrm_portable"

alias acg_q2='qmk generate-autocorrect-data "$KOZAK"/autocorrect_dictionary.txt -kb keychron/q2/ansi_encoder -km kozak'
alias acg_q60='qmk generate-autocorrect-data "$KOZAK"/autocorrect_dictionary.txt -kb keychron/q60/ansi -km kozak'
alias acg_tempo='qmk generate-autocorrect-data "$KOZAK"/autocorrect_dictionary.txt -kb mode/m60h -km kozak'
alias acg_m0115='qmk generate-autocorrect-data "$KOZAK"/autocorrect_dictionary.txt -kb converter/adb_usb/kozak -km m0115'
alias acg_m0115v2='qmk generate-autocorrect-data "$KOZAK"/autocorrect_dictionary.txt -kb converter/adb_usb/kozak -km m0115v2'
alias acg_m0116='qmk generate-autocorrect-data "$KOZAK"/autocorrect_dictionary.txt -kb converter/adb_usb/kozak -km m0116'
alias acg_portable='qmk generate-autocorrect-data "$KOZAK"/autocorrect_dictionary.txt -kb converter/macintosh_portable -km kozak'
alias acg="acg_q2 && acg_q60 && acg_tempo && acg_m0115 && acg_m0115v2 && acg_m0116 && acg_portable"

alias acr="acrm; acg"
alias acr_q2='acrm_q2; acg_q2'
alias acr_q60='acrm_q60; acg_q60'
alias acr_tempo='acrm_tempo; acg_tempo'
alias acr_m0115='acrm_m0115; acg_m0115'
alias acr_m0115v2='acrm_m0115v2; acg_m0115v2'
alias acr_m0116='acrm_m0116; acg_m0116'
alias acr_portable='acrm_portable; acg_portable'



# build fn
function build {
    local sha="$(git rev-parse --short HEAD)"
    local board_name=""
    local kb=""
    local km="kozak"
    local file=""
    local ext="bin"
    local ac=

    if [[ "$1" == "q0" ]]; then
        board_name="q0"
        kb="$_q0c"
        file="$_q0f"
    elif [[ "$1" == "q2" ]]; then
        board_name="q2"
        kb="$_q2c"
        file="$_q2f"
        ac="acr_q2"
    elif [[ "$1" == "q60" ]]; then
        board_name="q60"
        kb="$_q60c"
        file="$_q60f"
        ac="acr_q60"
    elif [[ "$1" == "tempo" ]]; then
        board_name="tempo"
        kb="$_tempoc"
        file="$_tempof"
        ac="acr_tempo"
    elif [[ "$1" == "m0110" ]]; then
        board_name="m0110"
        kb="$_m0110c"
        km="m0110"
        file="$_m0110f"
        ext="hex"
    elif [[ "$1" == "m0120" ]]; then
        board_name="m0110-m0120"
        kb="$_m0110c"
        km="m0110_m0120"
        file="$_m0120f"
        ext="hex"
    elif [[ "$1" == "m0110a" ]]; then
        board_name="m0110a"
        kb="$_m0110c"
        km="m0110a"
        file="$_m0110af"
        ext="hex"
    elif [[ "$1" == "m0115" ]]; then
        board_name="m0115"
        kb="$_adbc"
        km="m0115"
        file="$_m0115f"
        ext="hex"
        ac="acr_m0115"
    elif [[ "$1" == "m0115v2" ]]; then
        board_name="m0115v2"
        kb="$_adbc"
        km="m0115v2"
        file="$_m0115v2f"
        ext="hex"
        ac="acr_m0115v2"
    elif [[ "$1" == "m0116" ]]; then
        board_name="m0116"
        kb="$_adbc"
        km="m0116"
        file="$_m0116f"
        ext="hex"
        ac="acr_m0116"
    elif [[ "$1" == "portable" ]]; then
        board_name="macintosh_portable"
        kb="$_portablec"
        km="kozak"
        file="$_portablef"
        ext="uf2"
        ac="acr_portable"
    else
        echo "invalid selection: $1"
        return
    fi

    if [[ "$board_name" == "" ]]; then
        echo "nothing to build"
        return
    fi

    echo "building the $board_name..."

    local fw_name="$board_name-kozak_$sha.$ext"

    if [[ ! -z "$ac" ]]; then
        echo "updating autocorrect definitions"
        eval $ac
    fi

    qmk clean
    qmk compile -kb "$kb" -km "$km"

    mv "$QMK_HOME/$file" "$BUILDS/$fw_name"

    echo "build successful!"
}
