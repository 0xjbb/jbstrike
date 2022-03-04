package cmd

func init(){
	genericCommand := &grumble.Command{
		Name: "Generic",
		Help: "Generic Functions",
		LongHelp: ""
	}

	App.AddCommand(genericCommand)

	genericCommand.AddCommand(&grumble.Command{
		Name: "download",
		Help: "Download a file from your cwd to the implant.",
		LongHelp: "Download a file from your cwd to the implant.",
		Run: func(){}
	})
	
	genericCommand.AddCommand(&grumble.Command{
		Name: "upload",
		Help: "Upload a file.",
		LongHelp: "Upload a file from the implant to the server.",
		Run: func(){}
	})

	genericCommand.AddCommand(&grumble.Command{
		Name: "ls",
		Help: "List directory",
		LongHelp: "Lists directory.",
		Run: func(){}
	})

	genericCommand.AddCommand(&grumble.Command{
		Name: "cd",
		Help: "Change directory",
		LongHelp: "Change directory.",
		Run: func(){}
	})

	genericCommand.AddCommand(&grumble.Command{
		Name: "mv",
		Help: "Move a file.",
		LongHelp: "Move a file.",
		Run: func(){}
	})

	genericCommand.AddCommand(&grumble.Command{
		Name: "cp",
		Help: "Copy a file",
		LongHelp: "Copy a file.",
		Run: func(){}
	})
	genericCommand.AddCommand(&grumble.Command{
		Name: "shell",
		Help: "Execute a shell cmd",
		LongHelp: "Execute a shell cmd.",
		Run: func(){}
	})

	genericCommand.AddCommand(&grumble.Command{
		Name: "powershell",
		Help: "Execute a pwoershell cmd",
		LongHelp: "Execute a powershell cmd.",
		Run: func(){}
	})


}