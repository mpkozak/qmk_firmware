#!/bin/bash



echo "<< QMK Kozak >>"


eval `qmk env | grep "QMK_HOME"`


# dirs
KOZAK="$QMK_HOME/_kozak"
BUILDS="$KOZAK/builds"



# active board dirs
_common="$QMK_HOME/keyboards/keychron/common"
_q0="$QMK_HOME/keyboards/keychron/q0"
_q2="$QMK_HOME/keyboards/keychron/q2"
_q60="$QMK_HOME/keyboards/keychron/q60"
_tempo="$QMK_HOME/keyboards/mode/m60h"
_adb="$QMK_HOME/keyboards/converter/adb_usb"

# custom keymaps
_q0km="$_q0/plus/keymaps/kozak"
_q2km="$_q2/ansi_encoder/keymaps/kozak"
_q60km="$_q60/ansi/keymaps/kozak"
_tempokm="$_tempo/keymaps/kozak"
_adbkm="$_adb/keymaps/kozak"

# customized keyboards
_q0c="keychron/q0/plus"
_q2c="keychron/q2/ansi_encoder"
_q60c="keychron/q60/ansi"
_tempoc="mode/m60h"
_adbc="converter/adb_usb/rev1"

# build filenames
_q0f="keychron_q0_plus_kozak.bin"
_q2f="keychron_q2_ansi_encoder_kozak.bin"
_q60f="keychron_q60_ansi_kozak.bin"
_tempof="mode_m60h_kozak.bin"
_adbf="converter_adb_usb_rev1_kozak.hex"


# fs aliases
alias b='open $BUILDS'

# edit aliases
alias common='cd $_common; e'
alias q0='cd "$_q0"; e'
alias q2='cd "$_q2"; e'
alias q60='cd "$_q60"; e'
alias tempo='cd "$_tempo"; e'
alias adb='cd "$_adb"; e'
alias ek='e "$KOZAK"'
alias e0='cd $_q0km; e'
alias e2='cd $_q2km; e'
alias e60='cd $_q60km; e'
alias etempo='cd $_tempokm; e'
alias eadb='cd $_adbkm; e'

# autocorrect aliases
alias ace='e "$KOZAK"/autocorrect_dictionary.txt'

alias acrm_q2='[ -e "$_q2"/ansi_encoder/keymaps/kozak/autocorrect_data.h ] && rm "$_q2"/ansi_encoder/keymaps/kozak/autocorrect_data.h'
alias acrm_q60='[ -e "$_q60"/ansi/keymaps/kozak/autocorrect_data.h ] && rm "$_q60"/ansi/keymaps/kozak/autocorrect_data.h'
alias acrm_tempo='[ -e "$_tempo"/keymaps/kozak/autocorrect_data.h ] && rm "$_tempo"/keymaps/kozak/autocorrect_data.h'
alias acrm="acrm_q2 && acrm_q60 && acrm_tempo"

alias acg_q2='qmk generate-autocorrect-data "$KOZAK"/autocorrect_dictionary.txt -kb keychron/q2/ansi_encoder -km kozak'
alias acg_q60='qmk generate-autocorrect-data "$KOZAK"/autocorrect_dictionary.txt -kb keychron/q60/ansi -km kozak'
alias acg_tempo='qmk generate-autocorrect-data "$KOZAK"/autocorrect_dictionary.txt -kb mode/m60h -km kozak'
# alias acg="acg_q2 && acg_q60 && acg_tempo"
alias acg="acg_q2 && acg_q60"

alias acr="acrm; acg"
alias acr_q2='acrm_q2; acg_q2'
alias acr_q60='acrm_q60; acg_q60'
alias acr_tempo='acrm_tempo; acg_tempo'



# build fn
function build {
    local sha="$(git rev-parse --short HEAD)"
    local board_name=""
    local kb=""
    local file=""
    local ext="bin"
    local ac=0

    if [[ "$1" == "q0" ]]; then
        board_name="q0"
        kb="$_q0c"
        file="$_q0f"
    elif [[ "$1" == "q2" ]]; then
        board_name="q2"
        kb="$_q2c"
        file="$_q2f"
        ac=1
    elif [[ "$1" == "q60" ]]; then
        board_name="q60"
        kb="$_q60c"
        file="$_q60f"
        ac=1
    elif [[ "$1" == "tempo" ]]; then
        board_name="tempo"
        kb="$_tempoc"
        file="$_tempof"
    elif [[ "$1" == "adb" ]]; then
        board_name="m0116"
        kb="$_adbc"
        file="$_adbf"
        ext="hex"
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

    if [[ $ac -eq 1 ]]; then
        echo "updating autocorrect definitions"
        acr
    fi

    qmk clean
    qmk compile -kb "$kb" -km kozak

    mv "$QMK_HOME/$file" "$BUILDS/$fw_name"

    echo "build successful!"
}
