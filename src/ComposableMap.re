[@bs.module "react-simple-maps"]
external composableMapClass : ReasonReact.reactClass = "ComposableMap";

[@bs.deriving abstract]
type projectionConfigT = {
  scale: int,
  xOffset: int,
  yOffset: int,
  rotation: array(int),
  precision: float,
};

[@bs.deriving abstract]
type jsProps = {
  width: int,
  height: int,
  projection: string,
  projectionConfig: projectionConfigT,
};

let fromOption = Js.Nullable.fromOption;

let make =
    (
      ~width=800,
      ~height=450,
      ~projection="times",
      ~projectionConfig,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=composableMapClass,
    ~props=jsProps(~width, ~height, ~projection, ~projectionConfig),
    children,
  );
