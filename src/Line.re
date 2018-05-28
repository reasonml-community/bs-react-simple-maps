[@bs.module "react-simple-maps"]
external lineClass : ReasonReact.reactClass = "Line";

type coords = (float, float);

[@bs.deriving abstract]
type coordinatesT = {
  start: coords,
  [@bs.as "end"]
  end_: coords,
};

[@bs.deriving abstract]
type lineT = {coordinates: coordinatesT};

/* TODO: buildPath */
[@bs.deriving abstract]
type jsProps = {
  line: lineT,
  tabable: bool,
  style: Types.style,
  preserveMarkerAspect: bool,
};

let make =
    (
      ~start: coords,
      ~stop: coords,
      ~tabable=true,
      ~style=Types.style(),
      ~preserveMarkerAspect=true,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=lineClass,
    ~props=
      jsProps(
        ~line=lineT(~coordinates=coordinatesT(~start, ~end_=stop)),
        ~tabable,
        ~style,
        ~preserveMarkerAspect,
      ),
    children,
  );
