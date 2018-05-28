open Types;

[@bs.module "react-simple-maps"]
external markerClass : ReasonReact.reactClass = "Marker";

[@bs.deriving abstract]
type markerT = {coordinates: (float, float)};

[@bs.deriving abstract]
type styleT = {
  default: ReactDOMRe.Style.t,
  hover: ReactDOMRe.Style.t,
  pressed: ReactDOMRe.Style.t,
};

[@bs.deriving abstract]
type jsProps = {
  marker: markerT,
  tabable: bool,
  style: Types.style,
  preserveMarkerAspect: bool,
};

let make =
    (
      ~marker,
      ~tabable=true,
      ~style=Types.style(),
      ~preserveMarkerAspect=true,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=markerClass,
    ~props=jsProps(~marker, ~tabable, ~style, ~preserveMarkerAspect),
    children,
  );
