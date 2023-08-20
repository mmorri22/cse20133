{"payload":{"allShortcutsEnabled":false,"fileTree":{"readings/reading07":{"items":[{"name":"Reading 7-1.jpg","path":"readings/reading07/Reading 7-1.jpg","contentType":"file"},{"name":"Thinking Man.gif","path":"readings/reading07/Thinking Man.gif","contentType":"file"},{"name":"pascal.c","path":"readings/reading07/pascal.c","contentType":"file"},{"name":"ptr_to_ptr_alloc_free.c","path":"readings/reading07/ptr_to_ptr_alloc_free.c","contentType":"file"},{"name":"static_str.c","path":"readings/reading07/static_str.c","contentType":"file"},{"name":"struct_dynamic.c","path":"readings/reading07/struct_dynamic.c","contentType":"file"}],"totalCount":6},"readings":{"items":[{"name":"reading01","path":"readings/reading01","contentType":"directory"},{"name":"reading02","path":"readings/reading02","contentType":"directory"},{"name":"reading03","path":"readings/reading03","contentType":"directory"},{"name":"reading04","path":"readings/reading04","contentType":"directory"},{"name":"reading05","path":"readings/reading05","contentType":"directory"},{"name":"reading06","path":"readings/reading06","contentType":"directory"},{"name":"reading07","path":"readings/reading07","contentType":"directory"},{"name":"Reading 1-1.ipynb","path":"readings/Reading 1-1.ipynb","contentType":"file"},{"name":"Reading 1-2.ipynb","path":"readings/Reading 1-2.ipynb","contentType":"file"},{"name":"Reading 1-3.ipynb","path":"readings/Reading 1-3.ipynb","contentType":"file"},{"name":"Reading 1-4.ipynb","path":"readings/Reading 1-4.ipynb","contentType":"file"},{"name":"Reading 2-1.ipynb","path":"readings/Reading 2-1.ipynb","contentType":"file"},{"name":"Reading 2-2.ipynb","path":"readings/Reading 2-2.ipynb","contentType":"file"},{"name":"Reading 2-3.ipynb","path":"readings/Reading 2-3.ipynb","contentType":"file"},{"name":"Reading 2-4.ipynb","path":"readings/Reading 2-4.ipynb","contentType":"file"},{"name":"Reading 3-1.ipynb","path":"readings/Reading 3-1.ipynb","contentType":"file"},{"name":"Reading 3-2.ipynb","path":"readings/Reading 3-2.ipynb","contentType":"file"},{"name":"Reading 3-3.ipynb","path":"readings/Reading 3-3.ipynb","contentType":"file"},{"name":"Reading 4-1.ipynb","path":"readings/Reading 4-1.ipynb","contentType":"file"},{"name":"Reading 4-2.ipynb","path":"readings/Reading 4-2.ipynb","contentType":"file"},{"name":"Reading 4-3.ipynb","path":"readings/Reading 4-3.ipynb","contentType":"file"},{"name":"Reading 4-4.ipynb","path":"readings/Reading 4-4.ipynb","contentType":"file"},{"name":"Reading 4-5.ipynb","path":"readings/Reading 4-5.ipynb","contentType":"file"},{"name":"Reading 5-1.ipynb","path":"readings/Reading 5-1.ipynb","contentType":"file"},{"name":"Reading 5-2.ipynb","path":"readings/Reading 5-2.ipynb","contentType":"file"},{"name":"Reading 5-3.ipynb","path":"readings/Reading 5-3.ipynb","contentType":"file"},{"name":"Reading 6-1.ipynb","path":"readings/Reading 6-1.ipynb","contentType":"file"},{"name":"Reading 6-2.ipynb","path":"readings/Reading 6-2.ipynb","contentType":"file"},{"name":"Reading 6-3.ipynb","path":"readings/Reading 6-3.ipynb","contentType":"file"},{"name":"Reading 6-4.ipynb","path":"readings/Reading 6-4.ipynb","contentType":"file"},{"name":"Reading 7-1.ipynb","path":"readings/Reading 7-1.ipynb","contentType":"file"},{"name":"Reading 7-2.ipynb","path":"readings/Reading 7-2.ipynb","contentType":"file"},{"name":"Reading 7-3.ipynb","path":"readings/Reading 7-3.ipynb","contentType":"file"},{"name":"Reading 7-4.ipynb","path":"readings/Reading 7-4.ipynb","contentType":"file"}],"totalCount":34},"":{"items":[{"name":"homeworks","path":"homeworks","contentType":"directory"},{"name":"inclass-sols","path":"inclass-sols","contentType":"directory"},{"name":"inclass","path":"inclass","contentType":"directory"},{"name":"readings","path":"readings","contentType":"directory"}],"totalCount":4}},"fileTreeProcessingTime":7.05845,"foldersToFetch":[],"reducedMotionEnabled":null,"repo":{"id":651324562,"defaultBranch":"main","name":"su23-cse20332","ownerLogin":"mmorri22","currentUserCanPush":false,"isFork":false,"isEmpty":false,"createdAt":"2023-06-09T02:12:54.000Z","ownerAvatar":"https://avatars.githubusercontent.com/u/48807588?v=4","public":true,"private":false,"isOrgOwned":false},"symbolsExpanded":false,"treeExpanded":true,"refInfo":{"name":"main","listCacheKey":"v0:1686277529.849618","canEdit":false,"refType":"branch","currentOid":"f86bc9872c548e4a5e9e1bd2acf01467c888d22d"},"path":"readings/reading07/struct_dynamic.c","currentUser":null,"blob":{"rawLines":["#include <stdio.h>","#include <stdlib.h>","","// struct definition","typedef struct simple{","\tint the_int;","\tdouble the_double;","\tfloat the_float;","} simple;","","/***************************************************************"," * Function Name: print_dynamic_struct"," * Pre-Conditions: simple* dynamic_struct"," * Post-Conditions: void"," *"," * Prints the addresses and data values of the struct."," **************************************************************/","void print_dynamic_struct( simple* dynamic_struct );","","int main(){","      //create a struct on the heap","      simple* dynamic_struct = (simple *)malloc( sizeof(simple) );","","\t\t\tdynamic_struct->the_int = 45;","\t\t\tdynamic_struct->the_float = (float)-1.1;","\t\t\tdynamic_struct->the_double = 45.1;","","\t\t\tfprintf( stdout, \"In main: %p %p\\n\", &dynamic_struct, dynamic_struct);","\t\t\tprint_dynamic_struct( dynamic_struct );","","\t\t\t// Always free dynamically allocated memory","\t\t\tfree( dynamic_struct );","","      return 0;","}","","void print_dynamic_struct( simple* dynamic_struct ){","","\tfprintf( stdout, \"In print_dynamic_struct: %p %p\\n\", &dynamic_struct, dynamic_struct);","\tfprintf( stdout, \"%d %p\\n\", dynamic_struct->the_int, &(dynamic_struct->the_int));","\tfprintf( stdout, \"%f %p\\n\", dynamic_struct->the_float, &(dynamic_struct->the_float));","\tfprintf( stdout, \"%lf %p\\n\", dynamic_struct->the_double, &(dynamic_struct->the_double));","","}"],"stylingDirectives":[[{"start":0,"end":8,"cssClass":"pl-k"},{"start":9,"end":18,"cssClass":"pl-s"}],[{"start":0,"end":8,"cssClass":"pl-k"},{"start":9,"end":19,"cssClass":"pl-s"}],[],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":7,"cssClass":"pl-k"},{"start":8,"end":14,"cssClass":"pl-k"},{"start":15,"end":21,"cssClass":"pl-smi"}],[{"start":1,"end":4,"cssClass":"pl-smi"},{"start":5,"end":12,"cssClass":"pl-c1"}],[{"start":1,"end":7,"cssClass":"pl-smi"},{"start":8,"end":18,"cssClass":"pl-c1"}],[{"start":1,"end":6,"cssClass":"pl-smi"},{"start":7,"end":16,"cssClass":"pl-c1"}],[{"start":2,"end":8,"cssClass":"pl-smi"}],[],[{"start":0,"end":64,"cssClass":"pl-c"}],[{"start":0,"end":38,"cssClass":"pl-c"}],[{"start":0,"end":41,"cssClass":"pl-c"}],[{"start":0,"end":24,"cssClass":"pl-c"}],[{"start":0,"end":2,"cssClass":"pl-c"}],[{"start":0,"end":54,"cssClass":"pl-c"}],[{"start":0,"end":64,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":25,"cssClass":"pl-en"},{"start":27,"end":33,"cssClass":"pl-smi"},{"start":33,"end":34,"cssClass":"pl-c1"},{"start":35,"end":49,"cssClass":"pl-s1"}],[],[{"start":0,"end":3,"cssClass":"pl-smi"},{"start":4,"end":8,"cssClass":"pl-en"}],[{"start":6,"end":35,"cssClass":"pl-c"}],[{"start":6,"end":12,"cssClass":"pl-smi"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":14,"end":28,"cssClass":"pl-s1"},{"start":29,"end":30,"cssClass":"pl-c1"},{"start":32,"end":38,"cssClass":"pl-smi"},{"start":39,"end":40,"cssClass":"pl-c1"},{"start":41,"end":47,"cssClass":"pl-en"},{"start":49,"end":55,"cssClass":"pl-k"},{"start":56,"end":62,"cssClass":"pl-s1"}],[],[{"start":3,"end":17,"cssClass":"pl-s1"},{"start":17,"end":19,"cssClass":"pl-c1"},{"start":19,"end":26,"cssClass":"pl-c1"},{"start":27,"end":28,"cssClass":"pl-c1"},{"start":29,"end":31,"cssClass":"pl-c1"}],[{"start":3,"end":17,"cssClass":"pl-s1"},{"start":17,"end":19,"cssClass":"pl-c1"},{"start":19,"end":28,"cssClass":"pl-c1"},{"start":29,"end":30,"cssClass":"pl-c1"},{"start":32,"end":37,"cssClass":"pl-smi"},{"start":38,"end":42,"cssClass":"pl-c1"}],[{"start":3,"end":17,"cssClass":"pl-s1"},{"start":17,"end":19,"cssClass":"pl-c1"},{"start":19,"end":29,"cssClass":"pl-c1"},{"start":30,"end":31,"cssClass":"pl-c1"},{"start":32,"end":36,"cssClass":"pl-c1"}],[],[{"start":3,"end":10,"cssClass":"pl-en"},{"start":12,"end":18,"cssClass":"pl-s1"},{"start":20,"end":38,"cssClass":"pl-s"},{"start":40,"end":41,"cssClass":"pl-c1"},{"start":41,"end":55,"cssClass":"pl-s1"},{"start":57,"end":71,"cssClass":"pl-s1"}],[{"start":3,"end":23,"cssClass":"pl-en"},{"start":25,"end":39,"cssClass":"pl-s1"}],[],[{"start":3,"end":46,"cssClass":"pl-c"}],[{"start":3,"end":7,"cssClass":"pl-en"},{"start":9,"end":23,"cssClass":"pl-s1"}],[],[{"start":6,"end":12,"cssClass":"pl-k"},{"start":13,"end":14,"cssClass":"pl-c1"}],[],[],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":25,"cssClass":"pl-en"},{"start":27,"end":33,"cssClass":"pl-smi"},{"start":33,"end":34,"cssClass":"pl-c1"},{"start":35,"end":49,"cssClass":"pl-s1"}],[],[{"start":1,"end":8,"cssClass":"pl-en"},{"start":10,"end":16,"cssClass":"pl-s1"},{"start":18,"end":52,"cssClass":"pl-s"},{"start":54,"end":55,"cssClass":"pl-c1"},{"start":55,"end":69,"cssClass":"pl-s1"},{"start":71,"end":85,"cssClass":"pl-s1"}],[{"start":1,"end":8,"cssClass":"pl-en"},{"start":10,"end":16,"cssClass":"pl-s1"},{"start":18,"end":27,"cssClass":"pl-s"},{"start":29,"end":43,"cssClass":"pl-s1"},{"start":43,"end":45,"cssClass":"pl-c1"},{"start":45,"end":52,"cssClass":"pl-c1"},{"start":54,"end":55,"cssClass":"pl-c1"},{"start":56,"end":70,"cssClass":"pl-s1"},{"start":70,"end":72,"cssClass":"pl-c1"},{"start":72,"end":79,"cssClass":"pl-c1"}],[{"start":1,"end":8,"cssClass":"pl-en"},{"start":10,"end":16,"cssClass":"pl-s1"},{"start":18,"end":27,"cssClass":"pl-s"},{"start":29,"end":43,"cssClass":"pl-s1"},{"start":43,"end":45,"cssClass":"pl-c1"},{"start":45,"end":54,"cssClass":"pl-c1"},{"start":56,"end":57,"cssClass":"pl-c1"},{"start":58,"end":72,"cssClass":"pl-s1"},{"start":72,"end":74,"cssClass":"pl-c1"},{"start":74,"end":83,"cssClass":"pl-c1"}],[{"start":1,"end":8,"cssClass":"pl-en"},{"start":10,"end":16,"cssClass":"pl-s1"},{"start":18,"end":28,"cssClass":"pl-s"},{"start":30,"end":44,"cssClass":"pl-s1"},{"start":44,"end":46,"cssClass":"pl-c1"},{"start":46,"end":56,"cssClass":"pl-c1"},{"start":58,"end":59,"cssClass":"pl-c1"},{"start":60,"end":74,"cssClass":"pl-s1"},{"start":74,"end":76,"cssClass":"pl-c1"},{"start":76,"end":86,"cssClass":"pl-c1"}],[],[]],"csv":null,"csvError":null,"dependabotInfo":{"showConfigurationBanner":false,"configFilePath":null,"networkDependabotPath":"/mmorri22/su23-cse20332/network/updates","dismissConfigurationNoticePath":"/settings/dismiss-notice/dependabot_configuration_notice","configurationNoticeDismissed":null,"repoAlertsPath":"/mmorri22/su23-cse20332/security/dependabot","repoSecurityAndAnalysisPath":"/mmorri22/su23-cse20332/settings/security_analysis","repoOwnerIsOrg":false,"currentUserCanAdminRepo":false},"displayName":"struct_dynamic.c","displayUrl":"https://github.com/mmorri22/su23-cse20332/blob/main/readings/reading07/struct_dynamic.c?raw=true","headerInfo":{"blobSize":"1.31 KB","deleteInfo":{"deleteTooltip":"You must be signed in to make or propose changes"},"editInfo":{"editTooltip":"You must be signed in to make or propose changes"},"ghDesktopPath":"https://desktop.github.com","gitLfsPath":null,"onBranch":true,"shortPath":"9f6606d","siteNavLoginPath":"/login?return_to=https%3A%2F%2Fgithub.com%2Fmmorri22%2Fsu23-cse20332%2Fblob%2Fmain%2Freadings%2Freading07%2Fstruct_dynamic.c","isCSV":false,"isRichtext":false,"toc":null,"lineInfo":{"truncatedLoc":"44","truncatedSloc":"34"},"mode":"file"},"image":false,"isCodeownersFile":null,"isPlain":false,"isValidLegacyIssueTemplate":false,"issueTemplateHelpUrl":"https://docs.github.com/articles/about-issue-and-pull-request-templates","issueTemplate":null,"discussionTemplate":null,"language":"C","languageID":41,"large":false,"loggedIn":false,"newDiscussionPath":"/mmorri22/su23-cse20332/discussions/new","newIssuePath":"/mmorri22/su23-cse20332/issues/new","planSupportInfo":{"repoIsFork":null,"repoOwnedByCurrentUser":null,"requestFullPath":"/mmorri22/su23-cse20332/blob/main/readings/reading07/struct_dynamic.c","showFreeOrgGatedFeatureMessage":null,"showPlanSupportBanner":null,"upgradeDataAttributes":null,"upgradePath":null},"publishBannersInfo":{"dismissActionNoticePath":"/settings/dismiss-notice/publish_action_from_dockerfile","dismissStackNoticePath":"/settings/dismiss-notice/publish_stack_from_file","releasePath":"/mmorri22/su23-cse20332/releases/new?marketplace=true","showPublishActionBanner":false,"showPublishStackBanner":false},"renderImageOrRaw":false,"richText":null,"renderedFileInfo":null,"shortPath":null,"tabSize":8,"topBannersInfo":{"overridingGlobalFundingFile":false,"globalPreferredFundingPath":null,"repoOwner":"mmorri22","repoName":"su23-cse20332","showInvalidCitationWarning":false,"citationHelpUrl":"https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-on-github/about-citation-files","showDependabotConfigurationBanner":false,"actionsOnboardingTip":null},"truncated":false,"viewable":true,"workflowRedirectUrl":null,"symbols":{"timedOut":false,"notAnalyzed":false,"symbols":[{"name":"simple","kind":"class","identStart":76,"identEnd":82,"extentStart":69,"extentEnd":137,"fullyQualifiedName":"simple","identUtf16":{"start":{"lineNumber":4,"utf16Col":15},"end":{"lineNumber":4,"utf16Col":21}},"extentUtf16":{"start":{"lineNumber":4,"utf16Col":8},"end":{"lineNumber":8,"utf16Col":1}}},{"name":"simple","kind":"type","identStart":138,"identEnd":144,"extentStart":61,"extentEnd":145,"fullyQualifiedName":"simple","identUtf16":{"start":{"lineNumber":8,"utf16Col":2},"end":{"lineNumber":8,"utf16Col":8}},"extentUtf16":{"start":{"lineNumber":4,"utf16Col":0},"end":{"lineNumber":8,"utf16Col":9}}},{"name":"print_dynamic_struct","kind":"function","identStart":446,"identEnd":466,"extentStart":446,"extentEnd":492,"fullyQualifiedName":"print_dynamic_struct","identUtf16":{"start":{"lineNumber":17,"utf16Col":5},"end":{"lineNumber":17,"utf16Col":25}},"extentUtf16":{"start":{"lineNumber":17,"utf16Col":5},"end":{"lineNumber":17,"utf16Col":51}}},{"name":"main","kind":"function","identStart":499,"identEnd":503,"extentStart":499,"extentEnd":505,"fullyQualifiedName":"main","identUtf16":{"start":{"lineNumber":19,"utf16Col":4},"end":{"lineNumber":19,"utf16Col":8}},"extentUtf16":{"start":{"lineNumber":19,"utf16Col":4},"end":{"lineNumber":19,"utf16Col":10}}},{"name":"print_dynamic_struct","kind":"function","identStart":944,"identEnd":964,"extentStart":944,"extentEnd":990,"fullyQualifiedName":"print_dynamic_struct","identUtf16":{"start":{"lineNumber":36,"utf16Col":5},"end":{"lineNumber":36,"utf16Col":25}},"extentUtf16":{"start":{"lineNumber":36,"utf16Col":5},"end":{"lineNumber":36,"utf16Col":51}}}]}},"copilotInfo":null,"csrf_tokens":{"/mmorri22/su23-cse20332/branches":{"post":"UWIlClV6_7cLVF7LXTXnYgeK3BSWuNzkk49wuW0btpQ3rhLrIz0KNX9ZF13AA9doOG7APuiFEZkA72tXy-oZYA"},"/repos/preferences":{"post":"BzRu0uKvyI2onQNJB4GhwdWygXnF_CxldhplnFMdsl_TBHHTFMIq8mAzSeZhOxHkGia5unsr84URTT2vE1RuyQ"}}},"title":"su23-cse20332/readings/reading07/struct_dynamic.c at main · mmorri22/su23-cse20332"}