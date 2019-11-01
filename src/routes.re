type content = {
    format: string,
    text: string
};

type post = {
    id: string,
    title: string,
    content: list(content)
  };

let posts =  [{
    id: "0",
    title: "Day 1: Lets write some JS.",
    content: [{
        format: "p",
        text: "
        I get asked a lot from friends and family with some or no programming experience what it takes to becoming a developer. A lot of times they may have taken a programming class in college or done a handful of tutorials online but do not have a direction or plan after that.  This post is for everyone out there who wants to get into making software. Since I primarily do full-stack web development, and this is a very approachable point of entry into the software world, I will be focusing on that. These \"days\" can be done back to back or have a few days inbetween. I am grouping them into days for the sake of organization. It is best to do a small bit day by day than to do a large amount of work once a week. I will be using a Mac for this tutorial.

        Here is a list of tools for getting started.

        >- The terminal app
        >- homebrew, follow the install guide https://brew.sh
        >- node and NPM
        >- Your favorite text or code editor, sublime text or vscode for me"
    }, {
        format: "code",
        text: "
        brew install node # installs node and npm"
    },{
        format: "code",
        text: "
        brew install node # installs node and npm
        brew install caskroom/cask/brew-cask # install installer for apps
        brew tap caskroom/versions
        brew cask install sublime-text # install Sublime Text application" 
    }, {
        format: "p", 
        text:"or https://code.visualstudio.com/Download (I use this at work)"
    }, {
        format: "code",
        text: "
        mkdir programming // makes a folder called programming, you can name this whatever you\'d like.
        cd programming // changes directory so that you will be in your programming directory.
        touch mynewfile.js // create a file named mynewfile.js.
        "
    }, { 
        format: "p", 
        text: "Let\'s write our first function."
    }, {
        format: "code",
        text: "
        // Functions can be as easy as add.
        const add = (x, y) =>  x + y
        // shorthand for
        const add = (x, y) => {
            return x + y
        }
        
        const sum = add(1,2)
        console.log(sum) // 3
        "
    }, {
        format: "p",
        text: "
        Think of a topic that interests you. I love music theory so I am going to write a simple function that tells me the fifth of any note.
        At this point you are thinking, show me the code!
        
        Or more involved like
        "
    }, {
        format: "code",
        text: "
        const getFifth = (note) => {
            const lowerCaseNote = note.toLowerCase()
            const fifth = {
                 c: 'd',
                 g: 'd',
                 d: 'a',
                 a: 'e',
                 e: 'b',
                 b: 'f#',
                 'f#': 'c#',
                 gb: 'db',
                 'c#': 'ab',
                 db: 'ab',
                 ab: 'eb',
                 eb: 'bb',
                 bb:'f',
                 f: 'c'
            }[lowerCaseNote]
            const formattedNote = `${fifth.charAt(0).toUpperCase()}${fifth.slice(1)}`
            return formattedNote
        }
        const fifthOfGb = getFifth('gb')
        console.log(`The fifth of Gb is ${fifthOfGb}`) // The fifth of Gb is Db"
    }, {
        format: "p",
        text: "
        First this function makes our input note lowercase so when we get the property (note) of our object (notes and their corresponding fifths) it will match one of the objects keys (left hand side of the object). 
        Then we get the property we passed in of the object. 
        Next we do some string manipulation to format our answer to how a user would expect the output.
        Finally, we return the result.
        
        Write your own function in the file you created. 
        Run the program, in this case: "
    }, {
        format: "code",
        text: "node mynewfile.js"
    }, {
        format: "p",
        text: "
        Congratulations! you have written your first function. 

        Tomorrow we will cover making your first Web App."
    },
    ]
}
]