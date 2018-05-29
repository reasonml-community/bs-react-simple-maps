# bs-simple-react-maps – [BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [react-simple-maps](https://github.com/zcreativelabs/react-simple-maps)

## Installation

```sh
npm install --save bs-react-simple-maps
```

In your `bsconfig.json`, include `"bs-react-simple-maps"` in the `bs-dependencies`.

## Examples

```sh
npm run start
# and in a separate tab
npm run examples
# then open localhost:3000
```

* [Basic](./examples/basic/basic.re)

## Usage

The API follows [react-simple-maps](https://github.com/zcreativelabs/react-simple-maps) rather closely, with a few exceptions:

* `Marker` takes a prop `coordinates` instead of a nested `{marker: {coordinates}}` object.
* `Line` takes props `start and `stop` instead of a nested `{line: {coordinates: {start, end}}}` object.

## Development

```sh
npm run start
```

### Tests

There will be some tests using [bs-jest](https://github.com/BuckleTypes/bs-jest).

```sh
npm run test
```

For now, we just test by looking at the [examples](./examples).

## Thanks

Thanks to [reason-react-example](https://github.com/chenglou/reason-react-example), [reason-react](https://github.com/reasonml/reason-react), and [bs-jest](https://github.com/BuckleTypes/bs-jest) for inspiration how to create a Reason library.
