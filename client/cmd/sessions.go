package cmd

func init(){
	genericCommand := &grumble.Command{
		Name: "sessions",
		Help: "Session Management",
		LongHelp: ""
	}

	App.AddCommand(genericCommand)

	genericCommand.AddCommand(&grumble.Command{
		Name: "use",
		Help: "USe a session.",
		LongHelp: "",
		Run: func(){}
	})

	genericCommand.AddCommand(&grumble.Command{
		Name: "session",
		Help: "Use a session.",
		LongHelp: "",
		Run: func(){


			
		}
	})


}