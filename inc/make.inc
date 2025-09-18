SCRIPTS = $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
PROJ_ROOT =  $(abspath $(SCRIPTS)/..)

BEEP_GOOD=/usr/share/sounds/Oxygen-Sys-App-Positive.ogg
BEEP_BAD=/usr/share/sounds/Oxygen-Sys-App-Error-Serious-Very.ogg
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

FAIL = (echo $(RED)$(1) failed$(NC); $(2) && paplay $(BEEP_BAD); exit 1)
SUCCEED = (echo $(GREEN)$(1) succeeded$(NC); $(2) && paplay $(BEEP_GOOD); exit 0)
# to use
# 	command || $(call FAIL, COMMAND_NAME, true)
# 	$(call SUCCEED, COMMAND_NAME, false)
#
# final true/false indicates whether to play a sound

