'use strict'

const express = require('express')

const app = express()
const router = express.Router()

app.use(express.json())
app.use(express.urlencoded({extended: false}))
app.use(express.static('public'))

const db = new Map()

const route = router.get('/:name', (req, res) => {
    const name = req.params.name
    if(db.has(name)){
        res.status(200).send(
            JSON.parse(db.get(name))
        );
    }else{
        res.status(200).send(
            ""
        );
    }
});

const put = router.put('/:name', (req, res) => {
    const name = req.params.name
    db.set(name, JSON.stringify(req.body))
    res.status(200).send();
});

const del = router.delete('/:name', (req, res) => {
    const name = req.params.name
    db.delete(name)
    res.status(200).send();
});

app.use('/store', route)
app.use('/store', put)
app.use('/store', del)

module.exports = app