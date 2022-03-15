package cmd

import (
	"fmt"
	"github.com/desertbit/grumble"
)

func init() {

	App.AddCommand(&grumble.Command{
		Name:     "download",
		Help:     "Download a file from your cwd to the implant.",
		LongHelp: "Download a file from your cwd to the implant.",
		Run: func(c *grumble.Context) error {
			return nil
		},
	})

	App.AddCommand(&grumble.Command{
		Name:     "upload",
		Help:     "Upload a file.",
		LongHelp: "Upload a file from the implant to the server.",
		Run: func(c *grumble.Context) error {
			return nil
		},
	})

	App.AddCommand(&grumble.Command{
		Name:     "ls",
		Help:     "List directory",
		LongHelp: "Lists directory.",
		Args: func(a *grumble.Args) {
			a.String("path", "Path")
		},

		Run: func(c *grumble.Context) error {
			if c.Args.String("path") == "" {
				fmt.Println("Arg is set")
			}
			
			fmt.Println("Arg is not set")

			return nil
		},
	})

	App.AddCommand(&grumble.Command{
		Name:     "cd",
		Help:     "Change directory",
		LongHelp: "Change directory.",
		Args: func(a *grumble.Args) {
			a.String("path", "Path to cd to.")
		},

		Run: func(c *grumble.Context) error {
			return nil
		},
	})

	App.AddCommand(&grumble.Command{
		Name:     "mv",
		Help:     "Move a file.",
		LongHelp: "Move a file.",
		Run: func(c *grumble.Context) error {
			return nil
		},
	})

	App.AddCommand(&grumble.Command{
		Name:     "cp",
		Help:     "Copy a file",
		LongHelp: "Copy a file.",
		Run: func(c *grumble.Context) error {
			return nil
		},
	})
	App.AddCommand(&grumble.Command{
		Name:     "shell",
		Help:     "Execute a shell cmd",
		LongHelp: "Execute a shell cmd.",
		Run: func(c *grumble.Context) error {
			return nil
		},
	})

	App.AddCommand(&grumble.Command{
		Name:     "powershell",
		Help:     "Execute a pwoershell cmd",
		LongHelp: "Execute a powershell cmd.",
		Run: func(c *grumble.Context) error {
			return nil
		},
	})

}
