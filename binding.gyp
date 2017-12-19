{
	"targets": [{
		"target_name": "myModule",
		"include_dirs" : [
			"<!(node -e \"require('nan')\")"
		],
		"sources": [
			"index.cc",
		]
	}]
}
