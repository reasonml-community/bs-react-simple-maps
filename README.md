# bs-react-simple-maps

[BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [react-simple-maps](https://github.com/zcreativelabs/react-simple-maps)

## Installation

```sh
npm install --save bs-react-simple-maps
```

In your `bsconfig.json`, include `"bs-react-simple-maps"` in the `bs-dependencies`.

## Examples

```reason
<ComposableMap
  projectionConfig=(ComposableMap.projectionConfigT(~scale=200, ()))
  width=1000
  height=600>
  <ZoomableGroup center=(0, 0)>
    <Geographies geography="/examples/world-50m.json">
      (
        (geographies, projection) =>
          Array.map(
            geography =>
              <Geography
                key=(Geography.id(geography))
                geography
                projection
                style=(
                  Types.style(
                    ~default=ReactDOMRe.Style.make(~fill="#ECEFF1", ()),
                    (),
                  )
                )
              />,
            geographies,
          )
      )
    </Geographies>
  </ZoomableGroup>
</ComposableMap>
```

To run other examples:

```sh
npm run start
# and in a separate tab
npm run examples
# then open localhost:3000
```

* [Basic map](./examples/basic-map/basic_map.re)
* [Simple markers](./examples/simple-markers/simple_markers.re)

## Usage

The API follows [react-simple-maps](https://github.com/zcreativelabs/react-simple-maps) rather closely, with a few exceptions:

* `Marker` takes a prop `coordinates` instead of a nested `{marker: {coordinates}}` object.
* `Line` takes props `start` and `stop` instead of a nested `{line: {coordinates: {start, end}}}` object.

## Limitations

* `Geographies` only supports a `string` for its `geographies` (i.e. a JSON file path).
* `Geography` and `Marker` don't support any events yet.
* `ZoomableGlobe` is not supported yet.

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
