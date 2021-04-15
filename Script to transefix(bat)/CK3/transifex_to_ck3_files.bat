:: BUILDER SETTINGS
set language="pl"
set charset="empty"
set project_folder="Spolszczenie_CK3"
set parser_version="0.1.11"


echo "Starting conversion of translated files from Transifex into the EU4 format for workshop delivery and automated mod building."
echo "Removing temp directory - might say does not exist. That is normal, just a precaution."
rd /s /q temp
echo "Starting compiling latest source strings directory for CK3 format into the temp supply directory"
::game
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english" "pliki\\en\\game\\localization\\english" "temp\\supply\\game\\localization\\english" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\bookmark" "pliki\\en\\game\\localization\\english\\bookmark" "temp\\supply\\game\\localization\\english\\bookmark" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\credits" "pliki\\en\\game\\localization\\english\\credits" "temp\\supply\\game\\localization\\english\\credits" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\culture" "pliki\\en\\game\\localization\\english\\culture" "temp\\supply\\game\\localization\\english\\culture" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\custom_localization" "pliki\\en\\game\\localization\\english\\custom_localization" "temp\\supply\\game\\localization\\english\\custom_localization" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\dynasties" "pliki\\en\\game\\localization\\english\\dynasties" "temp\\supply\\game\\localization\\english\\dynasties" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\dynasty_legacies" "pliki\\en\\game\\localization\\english\\dynasty_legacies" "temp\\supply\\game\\localization\\english\\dynasty_legacies" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\enum" "pliki\\en\\game\\localization\\english\\enum" "temp\\supply\\game\\localization\\english\\enum" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization" "pliki\\en\\game\\localization\\english\\event_localization" "temp\\supply\\game\\localization\\english\\event_localization" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\gui" "pliki\\en\\game\\localization\\english\\gui" "temp\\supply\\game\\localization\\english\\gui" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\interactions" "pliki\\en\\game\\localization\\english\\interactions" "temp\\supply\\game\\localization\\english\\interactions" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\lifestyles" "pliki\\en\\game\\localization\\english\\lifestyles" "temp\\supply\\game\\localization\\english\\lifestyles" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\load_tips" "pliki\\en\\game\\localization\\english\\load_tips" "temp\\supply\\game\\localization\\english\\load_tips" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\modifiers" "pliki\\en\\game\\localization\\english\\modifiers" "temp\\supply\\game\\localization\\english\\modifiers" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\names" "pliki\\en\\game\\localization\\english\\names" "temp\\supply\\game\\localization\\english\\names" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\opinions" "pliki\\en\\game\\localization\\english\\opinions" "temp\\supply\\game\\localization\\english\\opinions" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\portraits" "pliki\\en\\game\\localization\\english\\portraits" "temp\\supply\\game\\localization\\english\\portraits" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\religion" "pliki\\en\\game\\localization\\english\\religion" "temp\\supply\\game\\localization\\english\\religion" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\triggers" "pliki\\en\\game\\localization\\english\\triggers" "temp\\supply\\game\\localization\\english\\triggers" yaml

java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\activities" "pliki\\en\\game\\localization\\english\\event_localization\\activities" "temp\\supply\\game\\localization\\english\\event_localization\\activities" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\childhood" "pliki\\en\\game\\localization\\english\\event_localization\\childhood" "temp\\supply\\game\\localization\\english\\event_localization\\childhood" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\councillor_task_events" "pliki\\en\\game\\localization\\english\\event_localization\\councillor_task_events" "temp\\supply\\game\\localization\\english\\event_localization\\councillor_task_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\culture_events" "pliki\\en\\game\\localization\\english\\event_localization\\culture_events" "temp\\supply\\game\\localization\\english\\event_localization\\culture_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\death_events" "pliki\\en\\game\\localization\\english\\event_localization\\death_events" "temp\\supply\\game\\localization\\english\\event_localization\\death_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\decisions" "pliki\\en\\game\\localization\\english\\event_localization\\decisions" "temp\\supply\\game\\localization\\english\\event_localization\\decisions" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\experimental" "pliki\\en\\game\\localization\\english\\event_localization\\experimental" "temp\\supply\\game\\localization\\english\\event_localization\\experimental" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\government_events" "pliki\\en\\game\\localization\\english\\event_localization\\government_events" "temp\\supply\\game\\localization\\english\\event_localization\\government_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\lifestyle" "pliki\\en\\game\\localization\\english\\event_localization\\lifestyle" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\prison_events" "pliki\\en\\game\\localization\\english\\event_localization\\prison_events" "temp\\supply\\game\\localization\\english\\event_localization\\prison_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\relation_events" "pliki\\en\\game\\localization\\english\\event_localization\\relation_events" "temp\\supply\\game\\localization\\english\\event_localization\\relation_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\religion_events" "pliki\\en\\game\\localization\\english\\event_localization\\religion_events" "temp\\supply\\game\\localization\\english\\event_localization\\religion_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\schemes" "pliki\\en\\game\\localization\\english\\event_localization\\schemes" "temp\\supply\\game\\localization\\english\\event_localization\\schemes" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\secret_events" "pliki\\en\\game\\localization\\english\\event_localization\\secret_events" "temp\\supply\\game\\localization\\english\\event_localization\\secret_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\story_cycles" "pliki\\en\\game\\localization\\english\\event_localization\\story_cycles" "temp\\supply\\game\\localization\\english\\event_localization\\story_cycles" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\stress_events" "pliki\\en\\game\\localization\\english\\event_localization\\stress_events" "temp\\supply\\game\\localization\\english\\event_localization\\stress_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\trait_specific_events" "pliki\\en\\game\\localization\\english\\event_localization\\trait_specific_events" "temp\\supply\\game\\localization\\english\\event_localization\\trait_specific_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\yearly_events" "pliki\\en\\game\\localization\\english\\event_localization\\yearly_events" "temp\\supply\\game\\localization\\english\\event_localization\\yearly_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\war_event" "pliki\\en\\game\\localization\\english\\event_localization\\war_event" "temp\\supply\\game\\localization\\english\\event_localization\\war_event" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\lifestyle\\governance" "pliki\\en\\game\\localization\\english\\event_localization\\lifestyle\\governance" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\governance" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\lifestyle\\guile" "pliki\\en\\game\\localization\\english\\event_localization\\lifestyle\\guile" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\guile" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\lifestyle\\nickname" "pliki\\en\\game\\localization\\english\\event_localization\\lifestyle\\nickname" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\nickname" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\lifestyle\\scholarship" "pliki\\en\\game\\localization\\english\\event_localization\\lifestyle\\scholarship" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\scholarship" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\lifestyle\\statecraft" "pliki\\en\\game\\localization\\english\\event_localization\\lifestyle\\statecraft" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\statecraft" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\lifestyle\\warfare" "pliki\\en\\game\\localization\\english\\event_localization\\lifestyle\\warfare" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\warfare" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\councillor_task_events\\councillor_spouse_events" "pliki\\en\\game\\localization\\english\\event_localization\\councillor_task_events\\councillor_spouse_events" "temp\\supply\\game\\localization\\english\\event_localization\\councillor_task_events\\councillor_spouse_events" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\schemes\\abduct" "pliki\\en\\game\\localization\\english\\event_localization\\schemes\\abduct" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\abduct" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\schemes\\befriend" "pliki\\en\\game\\localization\\english\\event_localization\\schemes\\befriend" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\befriend" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\schemes\\claim_throne" "pliki\\en\\game\\localization\\english\\event_localization\\schemes\\claim_throne" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\claim_throne" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\schemes\\court" "pliki\\en\\game\\localization\\english\\event_localization\\schemes\\court" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\court" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\schemes\\fabricate_hook" "pliki\\en\\game\\localization\\english\\event_localization\\schemes\\fabricate_hook" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\fabricate_hook" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\schemes\\murder" "pliki\\en\\game\\localization\\english\\event_localization\\schemes\\murder" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\murder" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\schemes\\seduce" "pliki\\en\\game\\localization\\english\\event_localization\\schemes\\seduce" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\seduce" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\event_localization\\schemes\\sway" "pliki\\en\\game\\localization\\english\\event_localization\\schemes\\sway" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\sway" yaml
::jomini
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization" "pliki\\en\\jomini\\localization" "temp\\supply\\jomini\\localization" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization\\achievements" "pliki\\en\\jomini\\localization\\achievements" "temp\\supply\\jomini\\localization\\achievements" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization\\credits" "pliki\\en\\jomini\\localization\\credits" "temp\\supply\\jomini\\localization\\credits" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization\\frontend" "pliki\\en\\jomini\\localization\\frontend" "temp\\supply\\jomini\\localization\\frontend" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization\\jomini" "pliki\\en\\jomini\\localization\\jomini" "temp\\supply\\jomini\\localization\\jomini" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization\\pops" "pliki\\en\\jomini\\localization\\pops" "temp\\supply\\jomini\\localization\\pops" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization\\settings" "pliki\\en\\jomini\\localization\\settings" "temp\\supply\\jomini\\localization\\settings" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization\\social" "pliki\\en\\jomini\\localization\\social" "temp\\supply\\jomini\\localization\\social" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization\\jomini\\coat_of_arms" "pliki\\en\\jomini\\localization\\jomini\\coat_of_arms" "temp\\supply\\jomini\\localization\\jomini\\coat_of_arms" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization\\jomini\\map_editor" "pliki\\en\\jomini\\localization\\jomini\\map_editor" "temp\\supply\\jomini\\localization\\jomini\\map_editor" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization\\jomini\\multiplayer_gui" "pliki\\en\\jomini\\localization\\jomini\\multiplayer_gui" "temp\\supply\\jomini\\localization\\jomini\\multiplayer_gui" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\jomini\\localization\\jomini\\script_system" "pliki\\en\\jomini\\localization\\jomini\\script_system" "temp\\supply\\jomini\\localization\\jomini\\script_system" yaml
::clausewitz
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\clausewitz\\localization" "pliki\\en\\clausewitz\\localization" "temp\\supply\\clausewitz\\localization" yaml
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\clausewitz\\localization\\text_utils" "pliki\\en\\clausewitz\\localization\\text_utils" "temp\\supply\\clausewitz\\localization\\text_utils" yaml
::dlc
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_supply" "pliki\\%language%\\game\\localization\\english\\dlc\\fp1" "pliki\\en\\game\\localization\\english\\dlc\\fp1" "temp\\supply\\game\\localization\\english\\dlc\\fp1" yaml

echo "Starting compiling latest translations to desired language - in this case - polish."
::game
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english" "temp\\ck3\\game\\localization\\english" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\bookmark" "temp\\ck3\\game\\localization\\english\\bookmark" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\credits" "temp\\ck3\\game\\localization\\english\\credits" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\culture" "temp\\ck3\\game\\localization\\english\\culture" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\custom_localization" "temp\\ck3\\game\\localization\\english\\custom_localization" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\dynasties" "temp\\ck3\\game\\localization\\english\\dynasties" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\dynasty_legacies" "temp\\ck3\\game\\localization\\english\\dynasty_legacies" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\enum" "temp\\ck3\\game\\localization\\english\\enum" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization" "temp\\ck3\\game\\localization\\english\\event_localization" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\gui" "temp\\ck3\\game\\localization\\english\\gui" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\interactions" "temp\\ck3\\game\\localization\\english\\interactions" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\lifestyles" "temp\\ck3\\game\\localization\\english\\lifestyles" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\load_tips" "temp\\ck3\\game\\localization\\english\\load_tips" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\modifiers" "temp\\ck3\\game\\localization\\english\\modifiers" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\names" "temp\\ck3\\game\\localization\\english\\names" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\opinions" "temp\\ck3\\game\\localization\\english\\opinions" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\portraits" "temp\\ck3\\game\\localization\\english\\portraits" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\religion" "temp\\ck3\\game\\localization\\english\\religion" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\triggers" "temp\\ck3\\game\\localization\\english\\triggers" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\activities" "temp\\ck3\\game\\localization\\english\\event_localization\\activities" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\childhood" "temp\\ck3\\game\\localization\\english\\event_localization\\childhood" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\councillor_task_events" "temp\\ck3\\game\\localization\\english\\event_localization\\councillor_task_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\culture_events" "temp\\ck3\\game\\localization\\english\\event_localization\\culture_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\death_events" "temp\\ck3\\game\\localization\\english\\event_localization\\death_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\decisions" "temp\\ck3\\game\\localization\\english\\event_localization\\decisions" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\experimental" "temp\\ck3\\game\\localization\\english\\event_localization\\experimental" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\government_events" "temp\\ck3\\game\\localization\\english\\event_localization\\government_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle" "temp\\ck3\\game\\localization\\english\\event_localization\\lifestyle" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\prison_events" "temp\\ck3\\game\\localization\\english\\event_localization\\prison_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\relation_events" "temp\\ck3\\game\\localization\\english\\event_localization\\relation_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\religion_events" "temp\\ck3\\game\\localization\\english\\event_localization\\religion_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\schemes" "temp\\ck3\\game\\localization\\english\\event_localization\\schemes" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\secret_events" "temp\\ck3\\game\\localization\\english\\event_localization\\secret_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\story_cycles" "temp\\ck3\\game\\localization\\english\\event_localization\\story_cycles" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\stress_events" "temp\\ck3\\game\\localization\\english\\event_localization\\stress_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\trait_specific_events" "temp\\ck3\\game\\localization\\english\\event_localization\\trait_specific_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\yearly_events" "temp\\ck3\\game\\localization\\english\\event_localization\\yearly_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\war_event" "temp\\ck3\\game\\localization\\english\\event_localization\\war_event" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\governance" "temp\\ck3\\game\\localization\\english\\event_localization\\lifestyle\\governance" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\guile" "temp\\ck3\\game\\localization\\english\\event_localization\\lifestyle\\guile" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\nickname" "temp\\ck3\\game\\localization\\english\\event_localization\\lifestyle\\nickname" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\scholarship" "temp\\ck3\\game\\localization\\english\\event_localization\\lifestyle\\scholarship" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\statecraft" "temp\\ck3\\game\\localization\\english\\event_localization\\lifestyle\\statecraft" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\lifestyle\\warfare" "temp\\ck3\\game\\localization\\english\\event_localization\\lifestyle\\warfare" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\councillor_task_events\\councillor_spouse_events" "temp\\ck3\\game\\localization\\english\\event_localization\\councillor_task_events\\councillor_spouse_events" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\abduct" "temp\\ck3\\game\\localization\\english\\event_localization\\schemes\\abduct" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\befriend" "temp\\ck3\\game\\localization\\english\\event_localization\\schemes\\befriend" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\claim_throne" "temp\\ck3\\game\\localization\\english\\event_localization\\schemes\\claim_throne" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\court" "temp\\ck3\\game\\localization\\english\\event_localization\\schemes\\court" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\fabricate_hook" "temp\\ck3\\game\\localization\\english\\event_localization\\schemes\\fabricate_hook" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\murder" "temp\\ck3\\game\\localization\\english\\event_localization\\schemes\\murder" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\seduce" "temp\\ck3\\game\\localization\\english\\event_localization\\schemes\\seduce" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\event_localization\\schemes\\sway" "temp\\ck3\\game\\localization\\english\\event_localization\\schemes\\sway" "%charset%"
::jomini
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization" "temp\\ck3\\jomini\\localization" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization\\achievements" "temp\\ck3\\jomini\\localization\\achievements" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization\\credits" "temp\\ck3\\jomini\\localization\\credits" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization\\frontend" "temp\\ck3\\jomini\\localization\\frontend" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization\\jomini" "temp\\ck3\\jomini\\localization\\jomini" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization\\pops" "temp\\ck3\\jomini\\localization\\pops" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization\\settings" "temp\\ck3\\jomini\\localization\\settings" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization\\social" "temp\\ck3\\jomini\\localization\\social" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization\\jomini\\coat_of_arms" "temp\\ck3\\jomini\\localization\\jomini\\coat_of_arms" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization\\jomini\\map_editor" "temp\\ck3\\jomini\\localization\\jomini\\map_editor" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization\\jomini\\multiplayer_gui" "temp\\ck3\\jomini\\localization\\jomini\\multiplayer_gui" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\jomini\\localization\\jomini\\script_system" "temp\\ck3\\jomini\\localization\\jomini\\script_system" "%charset%"
::clausewitz
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\clausewitz\\localization" "temp\\ck3\\clausewitz\\localization" "%charset%"
java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\clausewitz\\localization\\text_utils" "temp\\ck3\\clausewitz\\localization\\text_utils" "%charset%"
::dlc

java -jar "tools\\LocaleParser\\bin\\LocaleParser-%parser_version%-SNAPSHOT.jar" "folder_to_eu4" "temp\\supply\\game\\localization\\english\\dlc\\fp1" "temp\\ck3\\game\\localization\\english\\dlc\\fp1" "%charset%"


cd "%project_folder%"
echo "Removing old localisations"
del /s /f /q game
mkdir game
del /s /f /q jomini
mkdir jomini
del /s /f /q clausewitz
mkdir clausewitz
del abcd.txt
cd ../
echo "Copying new localisation"
xcopy /s temp\\ck3 "%project_folder%"
echo "Cleaning up temp directory."
rd /s /q temp
echo "Temp directory cleaned up, goodbye, have a nice day! :smile:
pause