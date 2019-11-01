const getFifth = (note) => {
    const lowerCaseNote = note.toLowerCase()
    const fifth = {
        c: 'g',
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
console.log(`The fifth of Gb is ${fifthOfGb}`)
