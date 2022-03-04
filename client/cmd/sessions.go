package cmd

import (
	"fmt"
	"github.com/desertbit/grumble"
)

func init() {
	App.AddCommand(&grumble.Command{
		Name: "sessions",
		Help: "List current sessions",
		Run: func(c *grumble.Context) error {
			fmt.Println("This is a test.")
			return nil
		},
	})

}

func init() {
	genericCommand := &grumble.Command{
		Name:     "sessions",
		Help:     "Session Management",
		LongHelp: "",
	}

	App.AddCommand(genericCommand)

	genericCommand.AddCommand(&grumble.Command{
		Name:     "use",
		Help:     "Use a session.",
		LongHelp: "",
		Run: func(c *grumble.Context) error {
			return nil
		},
	})

	genericCommand.AddCommand(&grumble.Command{
		Name:     "session",
		Help:     "Use a session.",
		LongHelp: "",
		Run: func(c *grumble.Context) error {
			return nil
		},
	})

}
