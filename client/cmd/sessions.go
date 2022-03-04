package cmd

func init(){
	genericCommand := &grumble.Command{
		Name: "Sessions",
		Help: "Session Management",
		LongHelp: ""
	}

	App.AddCommand(genericCommand)

	genericCommand.AddCommand(&grumble.Command{
		Name: "download",
		Help: "Download a file from your cwd to the implant.",
		LongHelp: "Download a file from your cwd to the implant.",
		Run: func(){}
	})

}